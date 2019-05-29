#include "Seller.h"
#include "Product.h"
#include "Customer.h"
#include <vector>
#include "Human.h"


#include <string>

class Shop                               //клас Магазин. Маємо назву магазину, обираємо рандомно якийсь продукт, моделюємо процес його продажу
                                         // до цього процесу звичайно що залучається продавець та покупець
                                         // також маємо вектор продавців, продуктів та покупців,а також отримаєм значенння прибутку
{
    public:
        Shop(string name);
        void get_product(Product a);
        void sell_product(Product a, Customer b, Seller c);
        void get_seller(Seller a);
        void get_customer(Customer a);
        void show();
    private:
        string name;
        vector<Seller> sellers;
        vector<Product> products;
        vector<Customer> costumers;
        double profit;
};
