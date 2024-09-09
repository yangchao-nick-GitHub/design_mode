#ifndef _BEHAVIOR_H_
#define _BEHAVIOR_H_

#include <iostream>

using namespace std;

class FlyBahavior {
public:
    FlyBahavior() {}
    virtual void fly() = 0; 
};

class QuackBehavior {
public:
    QuackBehavior() {};
    virtual void quack() = 0;
};

class FlyWithWings : public FlyBahavior {
public:
    FlyWithWings() {}
    void fly() override
    {
        cout << "I'm flying!!" << endl;
    }
};

class FlyNoWay : public FlyBahavior {
public:
    FlyNoWay() {}
    void fly() override
    {
        cout << "I can't fly" << endl;
    }
};

class Quack : public QuackBehavior {
public:
    Quack() {}
    void quack() override
    {
        cout << "Quack" << endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    MuteQuack() {}
    void quack() override
    {
        cout << "<< Silence >>" << endl;
    }
};


#endif 