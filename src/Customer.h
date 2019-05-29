#include "Human.h"
#include <string>
#pragma once

using namespace std;

class Customer:public Human                     # клас Покупець : ім''я, вік та гроші покупця
{
    public:
        Customer(string name, int age, double money);
        int k = 0;      
        int money;

};
