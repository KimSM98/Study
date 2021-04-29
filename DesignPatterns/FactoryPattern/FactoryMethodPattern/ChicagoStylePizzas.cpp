#include <iostream>
#include "ChicagoStylePizzas.h"

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza()
{
	mName = "Chicago Style Deep Dish Cheese Pizza";
	mDough = "Extra Thick Crust Dough";
	mSauce = "Plum Tomato Sauce";

	mToppings.push_back("Shredded Mozzarella Cheese");
}

void ChicagoStyleCheesePizza::cut()
{
	cout << "Cutting the pizza into square slices" << '\n';
}

ChicagoStyleVeggiePizza::ChicagoStyleVeggiePizza()
{
	mName = "Chicago Deep Dish Veggie Pizza";
	mDough = "Extra Thick Crust Dough";
	mSauce = "Plum Tomato Sauce";

	mToppings.push_back("Shredded Mozzarella Cheese");
	mToppings.push_back("Black Olives");
	mToppings.push_back("Spinach");
	mToppings.push_back("Eggplant");
}

void ChicagoStyleVeggiePizza::cut()
{
	cout << "Cutting the pizza into square slices" << '\n';
}

ChicagoStyleClamPizza::ChicagoStyleClamPizza()
{
	mName = "Chicago Style Clam Pizza";
	mDough = "Extra Thick Crust Dough";
	mSauce = "Plum Tomato Sauce";

	mToppings.push_back("Shredded Mozzarella Cheese");
	mToppings.push_back("Frozen Clams from Chesapeake Bay");
}

void ChicagoStyleClamPizza::cut()
{
	cout << "Cutting the pizza into square slices" << '\n';
}

ChicagoStylePepperoniPizza::ChicagoStylePepperoniPizza()
{
	mName = "Chicago Style Pepperoni  Pizza";
	mDough = "Extra Thick Crust Dough";
	mSauce = "Plum Tomato Sauce";

	mToppings.push_back("Shredded Mozzarella Cheese");
	mToppings.push_back("Black Olives");
	mToppings.push_back("Spinach");
	mToppings.push_back("Eggplant");
	mToppings.push_back("Sliced Pepperoni");
}

void ChicagoStylePepperoniPizza::cut()
{
	cout << "Cutting the pizza into square slices" << '\n';
}