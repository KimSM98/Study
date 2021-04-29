#pragma once
#include "PizzaStore.h"

class NYPizzaStore : public PizzaStore
{
public:
	NYPizzaStore() {};

	Pizza* createPizza(string item) override;
};