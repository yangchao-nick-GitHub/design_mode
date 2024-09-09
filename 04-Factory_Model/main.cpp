#include <iostream>
#include <memory>

using namespace std;

class Shoes {
public:
    virtual ~Shoes() {}
    virtual void show() = 0;
};

class Clothe {
public:
    virtual void show() = 0;
};

class NikeShoes : public Shoes {
public:
    virtual void show() override
    {
        cout << "Nike shoes" << endl;
    }
};

class UniqloClothe : public Clothe {
public:
    virtual void show() override
    {
        cout << "Uniqlo clothe" << endl;
    }
};

template<typename AbstractProduct_T>
class AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProduct_T> create() = 0;
};

template<typename AbstractProduct_T, typename ConcreteProduct_T>
class ConcreteFactory : public AbstractFactory<AbstractProduct_T> {
public:
    virtual std::shared_ptr<AbstractProduct_T> create() override
    {
        return std::make_shared<ConcreteProduct_T>();
    }
};

int main()
{
    auto shoes_factory = std::make_shared<ConcreteFactory<Shoes, NikeShoes>>();
    auto clothe_factory = std::make_shared<ConcreteFactory<Clothe, UniqloClothe>>();
    auto shoes = shoes_factory->create();
    shoes->show();
    auto clothe = clothe_factory->create();
    clothe->show();
    return 0;
}