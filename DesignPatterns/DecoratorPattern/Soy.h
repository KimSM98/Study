#pragma once
#include "CondimentDecorator.h"

class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* beverage);
	string getDescription() const override;
	double cost() const;
};
