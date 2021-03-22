#pragma once
#include "CondimentDecorator.h"

class Milk : public CondimentDecorator
{
public:
	Milk(Beverage* beverage);
	string getDescription() const override;
	double cost() const;

private:
	Beverage* mBeverage;
};
