#include "Whip.h"

Whip::Whip(Beverage* beverage) : mBeverage(beverage)
{
}

string Whip::getDescription() const
{
	return mBeverage->getDescription() + " Whip";
}

double Whip::cost() const
{
	return .10f + mBeverage->cost();
}