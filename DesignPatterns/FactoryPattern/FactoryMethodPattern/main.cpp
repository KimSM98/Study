#include <iostream>
#include "PizzaStore.h"
#include "NYPizzaStore.h"
#include "ChicagoPizzaStore.h"
#include "Pizza.h"

using namespace std;

int main(int argc, char* argv[])
{
	PizzaStore* nyStore = new NYPizzaStore();
	PizzaStore* chicagoStore = new ChicagoPizzaStore();

	Pizza* pizza = nyStore->orderPizza("cheese");
	cout << "Ethan ordered a " << pizza->getName() << '\n' << '\n';

	pizza = chicagoStore->orderPizza("cheese");
	cout << "Joel ordered a " << pizza->getName() << '\n' << '\n';

	return 0;
}