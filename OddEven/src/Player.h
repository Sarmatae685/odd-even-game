#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
    std::string name = "noname";
    int my_result = 0;
public:
    void setName();
    void setResult(int ODD); // my_result will be initialized
    void writeResult();
};

#endif // PLAYER_H
