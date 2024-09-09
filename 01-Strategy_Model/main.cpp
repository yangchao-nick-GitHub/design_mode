#include <iostream>

#include "duck.hpp"


int main()
{
    std::shared_ptr<MallardDuck> mallard_ptr = std::make_shared<MallardDuck>();
    mallard_ptr->performFly();
    mallard_ptr->performQuack();
    mallard_ptr->display();
    
    std::shared_ptr<ModelDuck> model_ptr = std::make_shared<ModelDuck>();
    model_ptr->performFly();
    model_ptr->performQuack();
    model_ptr->display();



 



    return 0;
}