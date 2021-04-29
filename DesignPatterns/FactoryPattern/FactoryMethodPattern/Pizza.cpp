#include <iostream>
#include "Pizza.h"

void Pizza::prepare()
{
	cout << "Preparing " << mName << '\n';
	cout << "Tossing dough..." << '\n';
	cout << "Adding sauce..." << '\n';
	cout << "Adding toppings..." << '\n';

	for (string it : mToppings)
	{
		cout << "   " << it << '\n';
	}
}

void Pizza::bake()
{
	cout << "Bake for 25 minutes at 350" << '\n';
}

void Pizza::cut()
{
	cout << "Cutting the pizza into diagonal slices" << '\n';
}

void Pizza::box()
{
	cout << "Place pizza in official PizzaStore box" << '\n';
}

string Pizza::getName() const
{
	return mName;
}
