#include <string>
#pragma once

using namespace std;

class Product
{
    public:
        Product(string name, double price);   // Клас Product : Назва та ціна продукту; 
        void show();
        double get_price();
        string get_name();
        void changePrice(double q);
    private:
        string name;
        double price;
};
