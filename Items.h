#pragma once
#ifndef Items_hpp
#define Items_hpp
#include <string>
#include <iostream>
using namespace std;

class Items {
private:

	string ItemName;
	float ItemPrice;
	int ItemQuantity;

public:

	Items();

	Items(string iName, float iPrice, int iQuantity);

	void Name(string iName);
	string entername();
	void CalcPrice(float iPrice);
	float enterprice();
	void CalcQuant(int iQuantity);
	int enterquant();

};
#endif