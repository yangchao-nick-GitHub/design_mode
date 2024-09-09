#ifndef _DUCK_H_
#define _DUCK_H_

#include <iostream>
#include <memory>

#include "behavior.hpp"

class Duck {
public:
    Duck() {}
    void setFlyBehavior(std::shared_ptr<FlyBahavior> fb);
    void setQuackBehavior(std::shared_ptr<QuackBehavior> qb);
    void performFly();
    void performQuack();
    virtual void display() = 0;
protected:
    std::shared_ptr<FlyBahavior> flyBehavior_;
    std::shared_ptr<QuackBehavior> quackBehavior_;
};

class MallardDuck : public Duck {
public:
    MallardDuck();
    virtual void display() override;
};

class ModelDuck : public Duck {
public:
    ModelDuck();
    virtual void display() override;
};

#endif