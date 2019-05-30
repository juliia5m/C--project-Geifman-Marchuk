 #include <iostream>
#include <string>
#include "Human.h"
#include "Customer.h"
#include "Seller.h"
#include "Shop.h"
#include "ShopManager.h"
#include "Product.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

int random(int a, int b)
{
    return a + rand()%(b  - a);
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Ввод с консоли или файла?" << endl << "1 - консоль, 2 - файл" << endl;         //вибираєм звідки відбуватиметься ввід
    cin >> n;
    if(n == 1)
    {
        int time;
        double w;
        double e;
        int q;
        string name;
        cout << "Введите название магазина: ";        //вводимо дані
        cin >> name;
        Shop s(name);
        cout << "Введите количество дней" << endl;
        cin >> time;
        cout << endl;
        cout << "Введите количество товаров" << endl;
        cin >> q;
        vector<Product> products;
        vector<Customer> customers;
        vector<Seller> sellers;
        for(int i = 0; i < q; i++)
        {
            cout <<  endl;
            cout << "Имя товара: ";
            cin >> name;
            cout << endl << "Стоимость: ";
            cin >> w;
            Product a(name, w);
            products.push_back(a);
            s.get_product(a);
        }
        cout << "Введите количество продавцов" << endl;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cout << endl << "1: " << endl;
            cout << "Имя продавца: ";
            cin >> name;
            cout << endl << "Возраст: ";
            cin >> w;
            cout << endl << "Зарплата: ";
            cin >> e;
            Seller a(name, w, e);
            sellers.push_back(a);
            s.get_seller(a);
        }
        cout << "Введите количество покупателей" << endl;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cout << endl << "1: " << endl;
            cout << "Имя покупателя: ";
            cin >> name;
            cout << endl << "Возраст: ";
            cin >> w;
            cout << endl << "Деньги: ";
            cin >> e;
            Customer a(name, w, e);
            customers.push_back(a);
            s.get_customer(a);
        }
        for(int i = 0; i < time; i++)                      //в залежності від того,скільки продуктів продалось( не всі продаються,оскільки
                                                           //чим більше днів стоїть продукт,тим нижча ціна на нього або він взагалі
                                                           // вже не продається,обчислюється прибуток магазину
        {
            int a = random(0, products.size());
            int b = random(0, customers.size());
            int c = random(0, sellers.size());
            s.sell_product(products[a], customers[b], sellers[c]);
            if(i < 5)
                for(int j = 0; j < products.size(); j++)
                    products[j].changePrice(1 - 0.2*i);
            else
                for(int j = 0; j < products.size(); j++)
                    products[j].changePrice(0);
            cout << "Информация о магазине после " << i + 1 << " дня" << endl;
            s.show();
        }
    }
    else if(n == 2)
    {

    }
}
