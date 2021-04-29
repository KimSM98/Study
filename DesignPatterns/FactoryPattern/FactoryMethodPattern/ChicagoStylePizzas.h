#pragma once
#include "Pizza.h"

class ChicagoStyleCheesePizza : public Pizza
{
public:
	ChicagoStyleCheesePizza();

	void cut() override;
};

class ChicagoStyleVeggiePizza : public Pizza
{
public:
	ChicagoStyleVeggiePizza();

	void cut() override;
};

class ChicagoStyleClamPizza : public Pizza
{
public:
	ChicagoStyleClamPizza();

	void cut() override;
};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
	ChicagoStylePepperoniPizza();

	void cut() override;
};