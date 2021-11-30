#pragma once
#ifndef Items_hpp
#define Items_hpp
#include <string>
#include <iostream>
using namespace std;

class Items {
private:

	string itemName;
	float itemPrice;
	int itemQuantity;

public:

	Items();

	Items(string iName, float iPrice, int iQuantity);

	void ItemNames(string iName);
	string get_item_name();
	void ItemPrices(float iPrice);
	float get_item_price();
	void ItemQuantities(int iQuantity);
	int get_item_quantity();

};
#endif
