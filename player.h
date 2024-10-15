#ifndef PLAYER_H
#define PLAYER_H
#include <stdlib.h>
#include <ctime>
#include <string>
#include <iostream>
#include "counter.h"

using namespace std;

class Player
{

public:

    Player(string);
    bool Winner();
    void rollDie ();


    unsigned short getplayerRank(){return Ranks;};
    friend void Counter::movePosition(Player& );
    friend void Counter::freemoveCheck(Player& );
    string getName ()
    {
        return name;
    };

private:

    unsigned short numberThrown,Ranks;
    string name;


};

#endif // PLAYER_H

