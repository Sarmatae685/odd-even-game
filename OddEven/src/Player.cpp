#include "Player.h"
#include "utils.h"
#include <iostream>
#include <fstream>
using namespace std;

void Player::setName() {
    cout << "Enter your nickname: ";

    // Check if there are characters in the buffer
    // peek() only peeks in buffer. If it returns 10 (\n in ASCII), statement will be True
    // ignore() by default ALWAYS deletes one char from buffer
    // cin.ignore() will do deletion ONLY if there's a leftover '\n' in the buffer from previous input
    if (cin.peek() == '\n') cin.ignore();

    // without this check the first letter of the nickname would be deleted by cin.ignore()

    // getline reads cleaned buffer + new input
    getline(cin, this->name); // allows spaces in name, reads to Enter key

    clearScreen();
    cout << endl << "_______________Hello, " << name << "!_______________" << endl;
}

void Player::setResult(int ODD) {
	this->my_result = ODD;
}

void Player::writeResult() {
    ofstream fout;
    fout.open("Highscores.txt", fstream::app); // fstream::app - to avoid overwriting
    if (fout.is_open() == false) cout << "Error while writing a score" << endl;
    else {
        fout << this->name << endl;
        fout << this->my_result << endl;
    }
    fout.close();
}
