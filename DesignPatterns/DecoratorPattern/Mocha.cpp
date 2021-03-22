#include "Mocha.h"

Mocha::Mocha(Beverage* beverage)
{
	mBeverage = beverage;
}

string Mocha::getDescription() const
{
	return mBeverage->getDescription() + " Mocha";
}

double Mocha::cost() const
{
	return .20f + mBeverage->cost();
}