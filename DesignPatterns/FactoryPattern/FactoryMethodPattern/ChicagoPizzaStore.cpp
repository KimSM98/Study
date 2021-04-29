#include "ChicagoPizzaStore.h"
#include "ChicagoStylePizzas.h"

Pizza* ChicagoPizzaStore::createPizza(string item)
{
	Pizza* pizza = nullptr;

	if (item._Equal("cheese")) pizza = new ChicagoStyleCheesePizza();
	else if (item._Equal("veggie")) pizza = new ChicagoStyleVeggiePizza();
	else if (item._Equal("clam")) pizza = new ChicagoStyleClamPizza();
	else if (item._Equal("pepperoni")) pizza = new ChicagoStylePepperoniPizza();

	return pizza;
}