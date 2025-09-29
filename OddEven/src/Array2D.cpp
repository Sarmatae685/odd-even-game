#include "Array2D.h"
#include <iostream>
using namespace std;

void Array2D::set_N(int N) {
    this->N = N;  // set amount of rows and columns in matrix
}

void Array2D::allocateMemory() { // allocate memory for NEW Games (MyGame.cpp --> void MyGame::setDifficult())
    m_arr = new int* [N]; // allocate memory for vertical string of pointers (stocks)
    for (int i = 0; i < N; i++) {
        m_arr[i] = new int[N]; // allocate memory for the strings (rooms on stocks) to which the pointers will point
    }
}

int** Array2D::do_Memory(int N) { // allocate memory to DOWNLOAD SAVED games from file (MyGame.cpp --> int** MyGame::readFromFile())
    m_arr = new int* [N];
    for (int i = 0; i < N; i++) {
        m_arr[i] = new int[N];
    }
    return m_arr;
}

void Array2D::fillMatrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            m_arr[i][j] = -1; // marks an empty cell with the value -1
        }                   // is used when save game option is chosen and download matrix to file
    }                      // when load saved game from file, cells marked with -1 won't be filled with other values and remain empty
}

void Array2D::printMatrix() {
	cout << endl << "\t    ";   // indentation + spaces for alignment
	for (int i = 0; i < N; i++) {
        //  padding for i >= 10 numbers - this way all numbers will consist of 4 characters
		if (i >= 10) {
			cout << i << "  "; // for two-digit numbers
		}
		else
			cout << i << "   "; // for one-digit numbers
	}

	//     0   1   2   3      ← column numbers with alignment

	cout << endl << "\t" << "  -";  // indent + start of line
	for (int j = 0; j < N; j++)
		cout << "----";              // 4 hyphens per each column
	cout << endl;

	//  ----------------       ← top frame

	// Main loop
	for (int i = 0; i < N; i++) {
        // Row number
		cout << "\t";

		if (i >= 10) {
			cout << i;         // two-digit number
		}
		else {
			cout << i << " ";  // one-digit number + space
		}

        // Row elements
		for (int j = 0; j < N; j++)
		{
			if (m_arr[i][j] == -1) {
				cout << "|   ";    // opening vertical line for row's left side + empty cell --> |   |
			}                      // (-1 means empty, its for game pause mechanics, used in Array2D::fillMatrix())
			else {
				cout << "| " << m_arr[i][j] << " ";  // opening vertical line + cell content 0 or 1 (playing elements) --> | 0 | or | 1 |
			}
		}
		cout << "|";   // final closing vertical line for the row's right side ...|   | 0 | ←

		// Horizontal line below the row
		cout << endl << "\t" << "  -";
		for (int j = 0; j < N; j++)
		{
			cout << "----";
		}
		cout << endl;
	}
}

//destructor
Array2D::~Array2D() { // We delete memory in reverse order to its allocation.
    for (int i = 0; i < N; i++)
    {
        delete[] m_arr[i]; // first delete strings with values (rooms on stocks)
    }
    delete m_arr; // then delete vertical string of pointers (stocks) itself
}
