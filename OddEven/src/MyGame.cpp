#include "MyGame.h"
#include "Array2D.h"
#include "Display.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

MyGame::MyGame() {
    arr.steps = 0;
    arr.N = 0;
    arr.m_arr = nullptr;
}

void MyGame::setDifficult() {
    cout << endl;
    cout << "\t3 * 3" << endl;
    cout << "\t4 * 4" << endl;
	cout << "\t5 * 5" << endl;
	cout << "\t6 * 6" << endl;
	cout << "\t7 * 7" << endl;
	cout << "\tOwn size" << endl;
	cout << endl;

    int N;
    cout << "Select difficulty: ";
    while (true){
        cin >> N;

        // Clearing the input buffer
        cin.clear(); // clear the error flag
        cin.ignore(10000, '\n'); // deletes 10k chars from buffer, stops when new line is reached

        if (N < 3) {
            cout << "Too small, please select the difficulty again: ";
            continue;
        }
        else if (N > 10) {
            cout << "Too large, please select the difficulty again: ";
            continue;
        }
        else { // Array2D arr object is created as a field of class MyGame (check MyGame.h)
            arr.set_N(N);
            arr.allocateMemory();
            arr.fillMatrix();   // fill with -1 values (means empty cells)
            break;
        }
    }
}

void MyGame::handlePauseMenu() {
    // call this function when in Game() 'p/P' is selected
    printInFile(arr);
    char input;
    cout << "Enter 'c/C' to continue\n 'e/E' to exit: ";

    while (true) {
        cin >> input;
        cin.clear();
        cin.ignore(10000, '\n');

        if (input == 'c' || input == 'C'){
            // Simply reload the data into the existing matrix
            readFromFile(); // method updates arr.m_arr itself
            return; // exit function and back to Game() (same as break)
        }
        else if (input == 'e' || input == 'E') {
            confirmExit();
            return; // executing will jump to Game()
        }
        else {
            cout << "Wrong character, Enter 'c' or 'C' to continue: ";
        }
    }
}

bool MyGame::checkGameEnd() {
    clearScreen();


    arr.printMatrix();
    arr.steps++;

    // if steps == amount of cells, then matrix is full and game ends
    if (arr.steps == arr.N * arr.N) {
        result();
        return true; // game ended
    }
    return false; // game continues
}

void MyGame::result() {
    int ODD = 0, EVEN = 0;

    // Sum of rows
    for (int i = 0; i < arr.N; i++)
    {
        int sum = 0;
        for (int j = 0; j < arr.N; j++)
        {
            sum += arr.m_arr[i][j];
        }
        // it is still in outer loop's scope
        cout << "Row #" << i + 1 << ": " << sum << endl;

        if (sum % 2 == 0)
            EVEN++;
        else
            ODD++;

    }

    // Sum of columns
    for (int j = 0; j < arr.N; j++) // changed outer variable to "j" to avoid confusion
    {
        int sum = 0; // scope of sum is only in this particular loop
        for (int i = 0; i < arr.N; i++)
        {
            sum += arr.m_arr[i][j]; // notice [i][j] order
        }   // if outer loop was for (int i...) and inner for (j...), we would have [j][i] to capture columns only

        // it is still in outer loop's scope
        cout << "Column #" << j + 1 << ": " << sum << endl;

        if (sum % 2 == 0)
            EVEN++;
        else
            ODD++;
        }

    // Sum of diagonals
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < arr.N; i++)
    {
        for (int j = 0; j < arr.N; j++)
        {
            if (i == j) {
                sum1 += arr.m_arr[i][j]; // sum of diagonal from top left ([0][0]) to bottom right ([N-1][N-1]) angle of matrix
            }
            if (i == arr.N - 1 - j){ // -1 because everything starts from 0;
                sum2 += arr.m_arr[i][j]; // sum of diagonal from top right ([0][N-1]) to bottom left ([N-1][0])angle of matrix
            }
        }
    }

    // we are OUT of outer for-loop scope
    if (sum1 % 2 == 0)
		EVEN++;
	else
		ODD++;

	if (sum2 % 2 == 0)
		EVEN++;
	else
		ODD++;

    cout << "Main diagonal: " << sum1 << endl;
	cout << "Side diagonal: " << sum2 << endl;
	cout << "EVEN: " << EVEN << endl;
	cout << "ODD: " << ODD << endl;

	if (EVEN > ODD) cout << "EVEN wins!";
	else if (EVEN == ODD) cout << "Tie!";
    else {
        cout << "ODD wins!";
        // Player player object is also created as a field of class MyGame (check MyGame.h)
        player.setResult(ODD);
        player.writeResult();
    }
}

void MyGame::Game() {
    player.setName();
    arr.printMatrix();
    char i = ' ';
    char j = ' ';
    int i_int = 0;
    int j_int = 0;


    while (true) // main while-loop of the Game process
    {
        // Entering "i" coordinates
        while (true)
        {
            cout << "ODD Player\tEnter row[i] (range 0 - " << arr.N - 1 << ") (p/P for Pause): ";
            cin >> i;
            cin.clear();
            cin.ignore(10000, '\n');

            if (i == 'p' || i == 'P')
            {
                handlePauseMenu();
                continue;
            }

            i_int = i - '0'; // char to int
            if (i_int >= 0 && i_int < arr.N)
                break;
            else
                cout << "Number out of range" << endl;

        } // end while (true)-loop of "i" input

        // Entering "j" coordinates
        while (true)
        {
            cout << "ODD Player\tEnter column[j] (range 0 - " << arr.N - 1 << ") (p/P for Pause): ";
            cin >> j;
            cin.clear();
            cin.ignore(10000, '\n');

            if (j == 'p' || j == 'P')
            {
                handlePauseMenu();
                continue;
            }

            j_int = j - '0'; // char to int
            if (j_int >= 0 && j_int < arr.N)
                break;
            else
                cout << "Number out of range" << endl;
        }



        // Entering a value
        if (arr.m_arr[i_int][j_int] == -1) {
            while (true)
            {
                cout << "Enter value 0/1 ('P/p' for Pause):  ";
				char input;
				cin >> input;
                cin.clear();
                cin.ignore(10000, '\n');

                // handle Pause option
				if (input == 'p' || input == 'P') {
                    handlePauseMenu();
                    continue;
				}

                // handle entering a valid value option
                if (input == '0' || input == '1') {
                    arr.m_arr[i_int][j_int] = (input - '0'); // cast to int and immediately insert it into the matrix
                    break; // breaks loop for "Enter 0/1 ('P/p' for Pause)"
                }
                cout << "Invalid character, enter again" << endl; // if not 0/1 or p/P
                continue;
            }

        }
        else { // if NOT -1 (non-empty cell), than inform player and continue waiting for input
            cout << "This cell is already occupied, enter again " << endl;
			continue;
        }

        if (checkGameEnd()) {
            break;  // break the main-game-loop
        }



        // Computer's input
        while (true)
        {
            // generate random cell coords
            int i = rand() % arr.N; // limit range to arr.N (from 0 to arr.N-1)
            int j = rand() % arr.N;

            if (arr.m_arr[i][j] == -1) { // if selected cell is empty...
                int value = rand() % 2; // limit range to 2 (from 0 to 1)
                arr.m_arr[i][j] = value; // insert value generated by PC

                clearScreen();
                cout << "EVEN Player\tEnters in cell: [" << i << "][" << j << "]: " << value << endl;

                arr.printMatrix(); // print matrix after Computer's move
                cout << "Press Enter to continue...";
                cin.get();  // waits for Enter. It is needed to print Computer's move correctly (otherwise checkGameEnd() will clear the console with PC-move info)

                break; // PC did a move, than break this loop to back to << Entering "i" coordinates >>-loop
            }
            else {        //  if selected cell is NOT empty
                continue; //  generate another [i][j] until we get to an empty one
            }
        }

        if (checkGameEnd()) {
            break;  // break the main-game-loop
        }

    } // main while (true)-loop of the Game process
} // MyGame::Game() {

int MyGame::getSteps() {
    // If the matrix is not initialized, return 0
    if (arr.m_arr == nullptr || arr.N <= 0) {
        return 0;
    }
    return arr.steps;
}

int** MyGame::readFromFile() {
    ifstream fin;
    fin.open("Pausedgame.txt");

    if (fin.is_open() == false) {
        // cout << "Error while reading from file" << endl;
        return nullptr;
    }


    // Read matrix size from file
    fin >> arr.N;

    // Allocate memory for matrix
    arr.m_arr = arr.do_Memory(arr.N);

    // Read all matrix elements from file
    for (int i = 0; i < arr.N; i++) {
        for (int j = 0; j < arr.N; j++) {
            fin >> arr.m_arr[i][j];
        }
    }

    // Initialize arr.steps by counting filled cells after loading
    arr.steps = 0;
    for (int i = 0; i < arr.N; i++) {
        for (int j = 0; j < arr.N; j++) {
            if (arr.m_arr[i][j] == 0 || arr.m_arr[i][j] == 1)
                arr.steps++; // we only count the moves made
        }  // arr.m_arr[i][j] == -1 ignore (empty cells)
    }

    fin.close();
    return arr.m_arr;
}

void MyGame::confirmExit() {
    char choice;
    cout << "\nAre you sure you want to exit?" << endl;
    cout << "Your progress is saved." << endl;
    cout << "Press 'c/C' to continue game or 'e/E' to exit: ";

    while (true) {
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');

        if (choice == 'c' || choice == 'C') {
            cout << "Returning to game..." << endl;

            cout << "Press Enter to continue...";
            cin.get();

            // clear console and return previous game state:
            clearScreen();
            readFromFile(); // load saved game from "Pausedgame.txt"
            arr.printMatrix(); // show matrix


            // this text was mostly to check if game restored, but let it be
            cout << "\nGame state restored. Ready to continue!" << endl;


            return; // exit confirmExit(), return to handlePauseMenu(), then to the game
        }
        else if (choice == 'e' || choice == 'E') {
            cout << "\nYour progress has been saved" << endl;
            Display::printGoodbye();
            exit(1);
        }
        else {
            cout << "Invalid choice. Press 'c' to continue or 'e' to exit: ";
            // continue can be avoided, because no code to skip below
        }
    }
}

