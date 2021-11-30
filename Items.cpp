#include "Items.h"

Items::Items()
	:ItemName("")
	, ItemPrice(0)
	, ItemQuantity(0)
{
}


Items::Items(string iName, float iPrice, int iQuantity)
	:ItemName(iName)
	, ItemPrice(iPrice)
	, ItemQuantity(iQuantity)
{
}

void Items::CalcPrice(float iPrice)
{
	ItemPrice = iPrice;
}

void Items::CalcQuant(int iQuantity)
{
	ItemQuantity = iQuantity;
}

void Items::Name(std::string iName)
{
	ItemName = iName;
}

float Items::enterprice()
{
	return ItemPrice;
}

int Items::enterquant()
{
	return ItemQuantity;
}

string Items::entername()
{
	return ItemName;
}