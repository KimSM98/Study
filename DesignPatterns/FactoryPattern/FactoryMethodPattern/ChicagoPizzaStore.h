#pragma once
#include "PizzaStore.h"

class ChicagoPizzaStore : public PizzaStore
{
public:
	ChicagoPizzaStore() {};

	Pizza* createPizza(string item) override;
};