#include "NYPizzaStore.h"
#include "NYStylePizzas.h"

Pizza* NYPizzaStore::createPizza(string item)
{
	Pizza* pizza = nullptr;

	if (item._Equal("cheese")) pizza = new NYStyleCheesePizza();
	else if (item._Equal("veggie")) pizza = new NYStyleVeggiePizza();
	else if (item._Equal("clam")) pizza = new NYStyleClamPizza();
	else if (item._Equal("pepperoni")) pizza = new NYStylePepperoniPizza();
	
	return pizza;
}