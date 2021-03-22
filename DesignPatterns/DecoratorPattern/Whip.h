#pragma once
#include "CondimentDecorator.h"

class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* beverage);
	string getDescription() const override;
	double cost() const;

private:
	Beverage* mBeverage;
};

