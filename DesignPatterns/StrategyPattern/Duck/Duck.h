#pragma once
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck
{
public:
	Duck();
	~Duck();

	virtual void display();
	void performFly();
	void performQuack();
	void swim();

	void setFlyBehavior(FlyBehavior* fb);
	void setQuckBehavior(QuackBehavior* qb);

private:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck();

	void display();
};

class ModelDuck :public Duck
{
public:
	ModelDuck();

	void display();
};