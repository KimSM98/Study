#include "NYStylePizzas.h"

NYStyleCheesePizza::NYStyleCheesePizza()
{
	mName = "NY Style Sause and Cheese Pizza";
	mDough = "Thin Crust Dough";
	mSauce = "Marinara Sauce";

	mToppings.push_back("Grated Reggiano Cheese");
}

NYStyleVeggiePizza::NYStyleVeggiePizza()
{
	mName = "NY Style Veggie Pizza";
	mDough = "Thin Crust Dough";
	mSauce = "Marinara Sauce";

	mToppings.push_back("Grated Reggiano Cheese");
	mToppings.push_back("Garlic");
	mToppings.push_back("Onion");
	mToppings.push_back("Mushrooms");
	mToppings.push_back("Red Pepper");

}

NYStyleClamPizza::NYStyleClamPizza()
{
	mName = "NY Style Clam Pizza";
	mDough = "Thin Crust Dough";
	mSauce = "Marinara Sauce";

	mToppings.push_back("Grated Reggiano Cheese");
	mToppings.push_back("Fresh Clams from Long Island Sound");
}

NYStylePepperoniPizza::NYStylePepperoniPizza()
{
	mName = "NY Style Pepperoni Pizza";
	mDough = "Thin Crust Dough";
	mSauce = "Marinara Sauce";

	mToppings.push_back("Grated Reggiano Cheese");
	mToppings.push_back("Sliced Pepperoni");
	mToppings.push_back("Garlic");
	mToppings.push_back("Onion");
	mToppings.push_back("Mushrooms");
	mToppings.push_back("Red Pepper");
}