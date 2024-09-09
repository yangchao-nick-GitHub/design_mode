#include "duck.hpp"

void Duck::setFlyBehavior(std::shared_ptr<FlyBahavior> fb)
{
    flyBehavior_ = fb;
}

void Duck::setQuackBehavior(std::shared_ptr<QuackBehavior> qb)
{
    quackBehavior_ = qb;
}

void Duck::performFly()
{
    flyBehavior_->fly();
}

void Duck::performQuack()
{
    quackBehavior_->quack();
}

MallardDuck::MallardDuck()
{
    flyBehavior_ = std::make_shared<FlyWithWings>();
    quackBehavior_ = std::make_shared<Quack>();
}

void MallardDuck::display()
{
    std::cout << "I'm a real Mallard duck" << std::endl;
}

ModelDuck::ModelDuck()
{
    flyBehavior_ = std::make_shared<FlyNoWay>();
    quackBehavior_ = std::make_shared<MuteQuack>();

}

void ModelDuck::display()
{
    std::cout << "I'm a model duck" << std::endl;
}