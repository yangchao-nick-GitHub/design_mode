#include <iostream>
#include <memory>

using namespace std;

class Component {
public:
    virtual ~Component() {}
    virtual void takeClother() = 0;
};

class ConcreteComponent :  public Component {
public:
    ConcreteComponent() {}

    virtual void takeClother() override
    {
        std::cout << "Put on basic clother!" << std::endl;
    }
};

class Decorator : public Component {
public:
    Decorator(shared_ptr<Component> component) : component_(component) {}
    virtual void takeClother() override
    {
        component_->takeClother();
    }
private:
    shared_ptr<Component> component_;
};

class UnderwearDecorator : public Decorator {
public:
    UnderwearDecorator(shared_ptr<Component> component) : Decorator(component) {}
    void takeClother() override
    {
        Decorator::takeClother();
        std::cout << "Put on underwear!" << std::endl;
    }
};

class SweaterDecorator : public Decorator {
public:
    SweaterDecorator(shared_ptr<Component> component) : Decorator(component) {}
    void takeClother() override
    {
        Decorator::takeClother();
        std::cout << "Put on sweater!" << std::endl;
    }
};

class CoatDeecorator : public Decorator {
public:
    CoatDeecorator(shared_ptr<Component> component) : Decorator(component) {}
    void takeClother() override
    {
        Decorator::takeClother();
        std::cout << "Put on coat!" << std::endl;
    }
};

int main()
{
    shared_ptr<Component> component = make_shared<ConcreteComponent>();
    shared_ptr<Component> component_a = make_shared<UnderwearDecorator>(component);
    shared_ptr<Component> component_b = make_shared<SweaterDecorator>(component_a);
    shared_ptr<Component> component_c = make_shared<CoatDeecorator>(component_b);
    component_c->takeClother();

    return 0;
}