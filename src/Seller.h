#include "Human.h"
#include <string>
#pragma once

extern bool Error;

class Seller:public Human
{
    public:
        Seller(string name, int age, double salary);
        void show();
        void changeSalary(double q);
        int quantity = 0;
    private:
        double salary;

};
