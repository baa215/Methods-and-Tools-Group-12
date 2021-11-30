#include "Items.h"

Items::Items()
	:itemName("")
	, itemPrice(0)
	, itemQuantity(0)
{
}


Items::Items(string iName, float iPrice, int iQuantity)
	:itemName(iName)
	, itemPrice(iPrice)
	, itemQuantity(iQuantity)
{
}
void Items::ItemNames(std::string iName)
{
	itemName = iName;
}
string Items::get_item_name()
{
	return itemName;
}
void Items::ItemPrices(float iPrice)
{
	itemPrice = iPrice;
}
float Items::get_item_price()
{
	return itemPrice;
}
void Items::ItemQuantities(int iQuantity)
{
	itemQuantity = iQuantity;
}
int Items::get_item_quantity()
{
	return itemQuantity;
}

