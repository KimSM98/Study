#include "Milk.h"

Milk::Milk(Beverage* beverage) : mBeverage(beverage)
{
}

string Milk::getDescription() const
{
	return mBeverage->getDescription() + " Milk";
}

double Milk::cost() const
{
	return .10f + mBeverage->cost();
}