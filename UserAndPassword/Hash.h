#pragma once
#include<iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <sstream>
#include "Hashtable.h"

/*
Student Name: Blade Arnold
Student NetID: baa215
Compiler Used: Visual Studio
Program Description:
This program uses a hash to sort users and passwords and store and save them.
*/
using namespace std;



class Hash
{
private:
	Hashtable table;


public:


	void readpwd(string filename); // read the password

	void savepwd(string filename); // saves the password

	void readdata(istream& is, string prompt); // executes all the commands

	void load(string file, string prompt); // load function

};