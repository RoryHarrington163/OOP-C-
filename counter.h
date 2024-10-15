#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
#include <string>

using namespace std;

class Player;

class Counter{

    public:
        Counter(string);
        void movePosition(Player& );
        void captured();
        void Print();
        void cageEscape();
        void intheCage();
        bool HomestrechBlue;
        void freemoveCheck(Player& );
        unsigned short getPosition () {return Position;};
    private:
        string colour;
        unsigned short Position;
        bool inCage;
};

#endif // COUNTER_H
