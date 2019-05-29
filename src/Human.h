#include <string>
#pragma once

using namespace std;

class Human
{
    public:                                            // клас Людина: ім''я та вік людини
        Human(string name, double age);
        virtual void show();
    protected:
        string name;
        int age;
};
