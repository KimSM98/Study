#include "Soy.h"

Soy::Soy(Beverage* beverage) : mBeverage(beverage)
{
}

string Soy::getDescription() const
{
	return mBeverage->getDescription() + " Soy";
}

double Soy::cost() const
{
	return .15f + mBeverage->cost();
}