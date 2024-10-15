#include <iostream>
#include <ctime>
#include <conio.h>
#include <fstream>
#include "counter.h"
#include "player.h"
using namespace std;
///Author @RoryHarrington

Player Player1("Player1");
Player Player2  ("Player 2");
Counter blueCounter ("Blue counter");
Counter orangeCounter ("Orange counter");

char replaytheGame;
bool Winner;
int main()
{
    do{
srand((unsigned) time(0)); // Do this once only to set the random seed.

do{
        Player1.rollDie();
        blueCounter.movePosition(Player1);
        blueCounter.freemoveCheck(Player1);
        blueCounter.Print();
        getch ();
        Player2.rollDie ();
        orangeCounter.movePosition (Player2);
        orangeCounter.freemoveCheck(Player2);
        orangeCounter.Print();

        if (orangeCounter.getPosition() == blueCounter.getPosition())
        {blueCounter.captured();cout << Player2.getName() << "'s counter landed on ,"<< Player1.getName() <<"'s counter is  sent back in the cage";}


        else if (blueCounter.getPosition() == orangeCounter.getPosition())
        {orangeCounter.captured();cout << Player1.getName() << "'s counter landed on ,"<< Player2.getName() <<"'s counter is  sent back in the cage";}

        if (blueCounter.getPosition () >= 15 && blueCounter.getPosition() < 20 )
        {
            cout << "Blue counter is on the track home";
        }
       else if ( orangeCounter.getPosition () >= 35 && orangeCounter.getPosition() < 40)
        {
            cout << "orange counter is on the track home";

        }

        else if (blueCounter.getPosition() == 20)

        {   Winner = true;

            cout << Player1.getName() << "'s  rank  has gone up by "<< Player1.getplayerRank() +1 << "\n";
            cout << Player1.getName() <<" is the winner " << "\n";
        }
       if (orangeCounter.getPosition() == 40)
        {
            Winner = true;

            cout << Player2.getName() << "rank  has gone up by "<< Player2.getplayerRank() +1 << "\n";
            cout << Player2.getName() <<" is the winner " << "\n";
        }
    }
    while (!Winner);
    cout << "\n\tDo you want to play again Y/N: ";
    cin >> replaytheGame;
   if(replaytheGame=='y'|| replaytheGame == 'Y'){
        blueCounter.intheCage();
        orangeCounter.intheCage();
        Winner = false;
        cout <<"\n\tNEW GAME\n";
}
    }
   while (replaytheGame != 'N');
}
