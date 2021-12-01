#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#include <fstream>
#define INTSIZE 23

using namespace std;




string user;
string pass;

int LoginCheck(string user, string pass)
{
    ifstream file;
    string username, password;
    int n = 0;
    file.open("user.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> username >> password;
            n++;
            if (user == username && pass == password)
                return n;
        }
    }
    else
    {
        cout << "file not open" << endl;
    }
    return 0;
}

void Register()
{
    ifstream file;
    ofstream newuser;
    string username, password, passwordconfirm, pay, address;
    file.open("user.txt", ios::app);
    newuser.open("user.txt", ios::app);
    bool uservalid = false;
    while (!uservalid)
    {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> passwordconfirm;
        cout << "Address: ";
        cin >> address;
        cout << "Payment: ";
        cin >> pay;
        int m = 0;
        int k = 0;
        while (file >> user >> pass)
        {
            m++;
            if (username != user)
                k++;
        }
        if (m == k && password == passwordconfirm)
            uservalid = true;
        else if (m != k)
            cout << "There is already a user with this username." << endl;
        else
            cout << "The passwords given do not match." << endl;
    }
    newuser << username << " " << password << " " << pay << " " << address << endl;;
    file.close();
    newuser.close();
}

void removeuser()
{
    while (LoginCheck(user, pass) == 0)
    {
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;
        if (LoginCheck(user, pass) != 0)
            cout << "Deleted " << user << "." << endl;
        else
        {
            cout << "Invalid username/password combination" << endl;
        }
    }
}