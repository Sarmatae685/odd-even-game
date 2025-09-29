#include "Display.h"
#include "utils.h" // clearScreen()
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void Display::printMenu() {
    cout << R"(
         _____   _   _    _____
        |     |_| |_| |  |   __|_ _ ___ ___
        |  |  | . | . |  |   __| | | -_|   |
        |_____|___|___|  |_____|\_/|___|_|_|
    )" << endl;


    cout << "\n\n";
    cout << "\t* New Game (n) ";

    cout << "\t\t\t\t\t\t\t";
    for (int j = 0; j < 3; j++)
        cout << "----";
    cout << endl;

    cout << "\t\t\t\t\t\t\t\t\t";
    for (int j = 0; j < 4; j++) {
        if (j == 0)
            cout << "| 1 ";
        else
            cout << "|   ";
    }

    cout << endl;

    cout << "\t* Download Game (d) ";

    cout << "\t\t\t\t\t\t";
	for (int j = 0; j < 3; j++)
		cout << "----";
	cout << endl;

	cout << "\t\t\t\t\t\t\t\t\t";
	for (int j = 0; j < 4; j++) {
		if (j == 1) {
			cout << "| 0 ";
		}
		else
		{
			cout << "|   ";
		}
	}
	cout << endl;

	cout << "\t* Best Results (s) ";

	cout << "\t\t\t\t\t\t";
	for (int j = 0; j < 3; j++)
		cout << "----";
	cout << endl;

	cout << "\t\t\t\t\t\t\t\t\t";
	for (int j = 0; j < 4; j++) {
		if (j == 2) {
			cout << "| 1 ";
		}
		else
		{
			cout << "|   ";
		}
	}
	cout << endl;

	cout << "\t* Exit (e) ";

	cout << "\t\t\t\t\t\t\t";
	for (int j = 0; j < 3; j++)
		cout << "----";
	cout << endl;
}

void Display::readResult() {
    clearScreen();
    cout << "\t\tBest Results" << endl;

    // Declare variables BEFORE the if-else block, so they'll be available in bubble sort's scope
    vector<int> results;
    vector<string> nicknames;

    ifstream fin;
    fin.open("Highscores.txt");
    if (fin.is_open() == false) cout << "No scores yet" << endl;
    else {
        int result;
		string nick;

        while (getline(fin, nick)) // while getline() reads nick-string from file, including spaces
        {      // getline automatically deletes \n from end of nick
            if (!nick.empty()) { // if read nickname is NOT empty (if it exists and readable)
                    // for ex. nick = "John Smith"
                nicknames.push_back(nick); // nicknames = ["John Smith"]

                fin >> result;             // for ex. result = 100
                results.push_back(result); // results = [100]

                fin.ignore(); //skip \n after 100
            }
        }

    }
    //Bubble Sort
    for (int i = 0; i < (int)results.size() - 1; i++) { //  results.size() returns type size_t (unsigned), so we need to cast it to int to be able -1
        for (int j = i + 1; j < (int)results.size(); j++) // j starts with i + 1, so we need to include last element in comparison --> j < (int)results.size()
        {
            if (results[i] < results[j])
            {
                int temp_int = results[i];
                results[i] = results[j];
                results[j] = temp_int;

                string temp_str = nicknames[i];
                nicknames[i] = nicknames[j];
                nicknames[j] = temp_str;
            }
        }
    }

    // Print only 5 best results
    for (int i = 0; i < 5; i++){
        if (i >= (int)results.size()){ // cast size_t to int
            cout << " - " << endl;
        }
        else {
            cout << i + 1 << ". " << nicknames[i] << "'s result: " << results[i] << endl;
        }
    }
    fin.close();

    // Select option: exit game or back to main menu
    cout << "\nPress 'b' to go back to main menu or 'e' to exit: ";
    char choice;
    while (true) {
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');

        if (choice == 'b' || choice == 'B') {
            clearScreen();
            printMenu();
            cout << "Your choice: ";

            return;
        }
        else if (choice == 'e' || choice == 'E') {
            Display::printGoodbye();
            exit(1);
        }
        else {
            cout << "Invalid choice. Press 'b' for back or 'e' for exit: ";
            // continue can be avoided, because there is no code below to skip
        }
    }
}

void Display::printGoodbye() {
    // static method: don't need to create object to print Goodbye graphics (check Display.h)
    cout << R"(
                         _____ _____ _____    __ __ _____
                        |   __|   __|   __|  |  |  |  _  |
                        |__   |   __|   __|  |_   _|     |
                        |_____|_____|_____|    |_| |__|__|
    )" << endl;
}
