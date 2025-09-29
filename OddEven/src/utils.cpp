#include "utils.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // for system()

using namespace std;

void printInFile(Array2D& arr) { // for function desc check "ulils.h"
    // it's friend func to Array2D class to read private fields: arr.N, arr.m_arr[i][j]


    // Implementation details:
    // 1. Opens "Pausedgame.txt" for writing
    // 2. First writes matrix size (arr.N)
    // 3. Then writes all matrix elements row by row

    ofstream fout;
    // If the file does not exist, it is created.
    // If it exists, it will be overwritten (old data will be lost)
    fout.open("Pausedgame.txt");
    if (fout.is_open() == false) cout << "Error while writing to file" << endl;
    else
    {   // first write matrix size
        fout << arr.N << endl;
        // then matrix itself
        for (int i = 0; i < arr.N; i++) // go through the rows of the matrix
        {
            for (int j = 0; j < arr.N; j++)  // go through the columns of the matrix
            {
                fout << arr.m_arr[i][j] << " "; // element + space
            }
            fout << endl;   // end line after each row of the matrix has been written
        }
    }
    fout.close();
}

void removeFile() {
    // Truncates the pause file to clear saved game dat
    fstream fout;
    fout.open("Pausedgame.txt", ios::out | ios::trunc);
    fout << " " << endl;
    fout.close();
}

void clearScreen() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}



