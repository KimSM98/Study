#pragma once
#include <string>
#include "Pizza.h"
class PizzaStore
{
public:
	PizzaStore() {};
	~PizzaStore() { delete this; }

	Pizza* orderPizza(std::string type)
	{
		Pizza* pizza = createPizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		
		return pizza;
	}

	virtual Pizza* createPizza(string type) { return nullptr; }
};