#include "counter.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "player.h"
using namespace std;
Counter::Counter(string colour)
{
    this->colour = colour;
    Position = 0;
    inCage = true;
    //only for thew blue counter  when location is 15 or more
    HomestrechBlue = false;

}
void Counter::Print()
{
    cout << this-> colour << " is at position " << Position << "\n";

}
void Counter::cageEscape()
{
    cout  << this->colour << "has escaped the cage.\n";
}

void Counter::movePosition(Player & thePlayer)
{

    if (thePlayer.numberThrown == 6 && inCage && !HomestrechBlue && colour == "Blue counter")
    {
        cageEscape();

        Position = 21;
        inCage = false;
        HomestrechBlue == true;
        Print();
        cout << thePlayer.getName() << " gets another die throw"<< "\n";

    }
    else if(!inCage && !HomestrechBlue && this ->colour == "Blue counter")
    {

        Position += thePlayer.numberThrown;
    }
    if( !inCage && Position > 40 && this ->colour == "Blue counter")
    {
        unsigned short corner= 40;
        Position -= corner;

    }

    if(!inCage &&Position >= 15 && Position < 20 && this ->colour == "Blue counter")
    {
        Position+=thePlayer.numberThrown;
        HomestrechBlue = true;
        cout << "you are on the home strech Blue\n";
    }



    if (!inCage && HomestrechBlue && Position >20 && this->colour == "Blue counter")
    {
        Position -= thePlayer.numberThrown;
        cout << "sorry you've gone over the home  " << "\n";

    }
    else if (!inCage && Position == 20 && this->colour == "Blue counter")
    {
        cout << thePlayer.getName() << " got the counter home\n";

    }
    if (thePlayer.numberThrown == 6 && inCage && colour == "Orange counter")
    {
        cageEscape();
        Position = 1;
        inCage = false;
        Print();
        cout << thePlayer.getName() << " gets another die throw"<< "\n";

    }
    else if(!inCage &&  this ->colour == "Orange counter")
    {
        Position+= thePlayer.numberThrown;
    }
    if (!inCage && Position > 40 && this->colour == "Orange counter")
    {
        Position-=thePlayer.numberThrown;
        cout << "sorry you have gone over the the home must get exact\n";
    }
    else if(!inCage && Position == 40 && this-> colour == "Orange counter")
    {
        cout << thePlayer.getName() << " got the counter home\n";
    }
    // Print();

}



void Counter::captured()
{

    inCage = true;
    HomestrechBlue = false;
    Position = 0;


}
void Counter::intheCage()
{
    inCage = true;
    HomestrechBlue = false;
    Position = 0;

}
void Counter::freemoveCheck(Player & thePlayer )
{
    while (thePlayer.numberThrown == 6 )
    {

        Print();
        cout << thePlayer.getName() << " gets another throw.\n"<< "\n";
        thePlayer.rollDie();
        movePosition(thePlayer);

    }

}
