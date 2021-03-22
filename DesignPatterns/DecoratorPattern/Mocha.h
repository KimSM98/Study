#pragma once
#include "CondimentDecorator.h"

class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* beverage);
	string getDescription() const override;
	double cost() const;

private:
	Beverage* mBeverage;
};
