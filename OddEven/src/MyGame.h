#ifndef MYGAME_H
#define MYGAME_H

#include "Array2D.h"
#include "Player.h"

class MyGame{
private:
    Array2D arr;
    Player player;
    void handlePauseMenu(); // handles Pause option
    void confirmExit();
public:
    MyGame();

    void setDifficult();
    void result();
    void Game();
    int** readFromFile();

    bool checkGameEnd(); // will change arr.steps field
    int getSteps();  // will only return arr.steps value so that it can be compared

};

#endif // MYGAME_H
