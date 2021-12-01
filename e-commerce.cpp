// e-commerce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

string name;
int item;
float price;

int quantity1;
int quantity2;
int quantity3;
int quantity4;
int quantity5;
int quantity6;



void addItems()
{
    int choice2;

    int quantity1;
    int quantity2;
    int quantity3;
    int quantity4;
    int quantity5;
    int quantity6;



    cin >> choice2;



    if (choice2 == 1)
    {

        quantity1++;

    }


    if (choice2 == 2)
    {
        quantity2++;
    }



    if (choice2 == 3)
    {
        quantity3++;
    }



    if (choice2 == 4)
    {
       quantity4++;
    }

    if (choice2 == 5)
    {
        quantity2++;
    }

    if (choice2 == 6)

    {
        quantity6++;
    }
}



void displayCart()
{
    cout << quantity1;
    cout << quantity2;
    cout << quantity3;
    cout << quantity4;
    cout << quantity5;
    cout << quantity6;
    
}


float totalCart()
{
    float total1;
    float total2;
    float total3;
    float total4;
    float total5;
    float total6;


    float price1;
    float price2;
    float price3;
    float price4;
    float price5;
    float price6;

    float totalofCart;


    total1 = quantity1 * price1;
    total2 = quantity2 * price2;
    total3 = quantity3 * price3;
    total4 = quantity4 * price4;
    total5 = quantity5 * price5;
    total6 = quantity6 * price6;

    totalofCart = total1 + total2 + total3 + total4 + total5 + total6;

}


int removeCart()

{
    int choice3;

    if (choice3 == 1)
    {

        quantity1--;

    }


    if (choice3 == 2)
    {
        quantity2--;
    }



    if (choice3 == 3)
    {
        quantity3--;
    }



    if (choice3 == 4)
    {
        quantity4--;
    }

    if (choice3 == 5)
    {
        quantity2--;
    }

    if (choice3 == 6)

    {
        quantity6--;
    }
}


    







