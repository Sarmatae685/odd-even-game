#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Display.h"
#include "MyGame.h"
#include "utils.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Display display;
	display.printMenu();
	char input;
	cout << "Your choice: ";

	while (true) {
        cin >> input;
        cin.clear();
        cin.ignore(10000, '\n');

        switch (input)
        {
            case 'n': {
                MyGame game;
                game.setDifficult();
                game.Game();
                break;
            }
            case 'd': {
                MyGame game;
                if (game.readFromFile() != nullptr && game.getSteps() > 0) {
                    game.Game();
                    removeFile();
                } else {
                    cout << "No saved game. Repeat your selection: ";
                    continue; // continue to wait for out option choice in menu
                }
                break;
            }
            case 's':
                display.readResult(); // readResult() has logic to exit program or get back to menu, so we continue to run in loop and make choice in readResult itself
                continue; // if we choose 'b' in readResult, we back right to this "continue" and new while iteration (with input wait) will start
            case 'e':
                Display::printGoodbye();
                exit(1);
                break;
            default:
                cout << "Invalid character. Repeat your selection: ";
                continue;
        }// end switch
        break;
	} // end while (true)
	return 0;
}
