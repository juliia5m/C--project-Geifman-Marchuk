#include <string>
#pragma once

using namespace std;

class Product
{
    public:
        Product(string name, double price);
        void show();
        double get_price();
        string get_name();
        void changePrice(double q);
    private:
        string name;
        double price;
};
