#include "player.h"
#include "String"
#include "counter.h"
#include <iostream>
#include "player.h"
#include "counter.h"
#include <stdlib.h>
#include <ctime>

using namespace std;


Player::Player(string Playername)
{

    cout << "please enter your name :";
    cin >>  name;
    Ranks == 0;
}

void Player::rollDie ()
{
    numberThrown = rand () % 6 + 1; // Generate a random number between 1 and 6.
    cout << "\n\t"<< name << " threw a "<< numberThrown <<" \n";
}
