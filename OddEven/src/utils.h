#ifndef UTILS_H
#define UTILS_H

#include "Array2D.h" // printInFile works with Array2D object directly via reference to an original object

void printInFile(Array2D& arr); // is friend function to Array2D class (check Array2D.h)
// I pass the object via a reference so that I don't have to describe a copy constructor in the Array2D class
// and extract the values from arr.N and arr.m_arr fields directly via a reference to the original Array2D object.

// it is called in MyGame::Game()when the player presses 'P' to pause
// Saves current game state to "Pausedgame.txt" file

// Pressing 'd' calls the MyGame::readFromFile() method to load matrix from "Pausedgame.txt" and continue to play.

void removeFile(); // clears/removes "Pausedgame.txt" file after game completion
void clearScreen();
#endif // UTILS_H
