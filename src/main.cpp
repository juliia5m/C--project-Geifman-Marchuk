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
    cout << "���� � ������� ��� �����?" << endl << "1 - �������, 2 - ����" << endl;
    cin >> n;
    if(n == 1)
    {
        int time;
        double w;
        double e;
        int q;
        string name;
        cout << "������� �������� ��������: ";
        cin >> name;
        Shop s(name);
        cout << "������� ���������� ����" << endl;
        cin >> time;
        cout << endl;
        cout << "������� ���������� �������" << endl;
        cin >> q;
        vector<Product> products;
        vector<Customer> customers;
        vector<Seller> sellers;
        for(int i = 0; i < q; i++)
        {
            cout <<  endl;
            cout << "��� ������: ";
            cin >> name;
            cout << endl << "���������: ";
            cin >> w;
            Product a(name, w);
            products.push_back(a);
            s.get_product(a);
        }
        cout << "������� ���������� ���������" << endl;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cout << endl << "1: " << endl;
            cout << "��� ��������: ";
            cin >> name;
            cout << endl << "�������: ";
            cin >> w;
            cout << endl << "��������: ";
            cin >> e;
            Seller a(name, w, e);
            sellers.push_back(a);
            s.get_seller(a);
        }
        cout << "������� ���������� �����������" << endl;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cout << endl << "1: " << endl;
            cout << "��� ����������: ";
            cin >> name;
            cout << endl << "�������: ";
            cin >> w;
            cout << endl << "������: ";
            cin >> e;
            Customer a(name, w, e);
            customers.push_back(a);
            s.get_customer(a);
        }
        for(int i = 0; i < time; i++)
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
            cout << "���������� � �������� ����� " << i + 1 << " ���" << endl;
            s.show();
        }
    }
    else if(n == 2)
    {

    }
}
