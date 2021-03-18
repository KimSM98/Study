#include "Duck.h"

Duck::Duck()
{
	flyBehavior = new FlyBehavior();
	quackBehavior = new QuackBehavior();
}

Duck::~Duck()
{
	delete flyBehavior;
	delete quackBehavior;
}

void Duck::display()
{
	std::cout << "I'm Default Duck." << '\n';
}

void Duck::performFly()
{
	flyBehavior->fly();
}

void Duck::performQuack()
{
	quackBehavior->quack();
}

void Duck::swim()
{
	std::cout << "Every Ducks can float." << '\n';
}

void Duck::setFlyBehavior(FlyBehavior* fb)
{
	flyBehavior = fb;
}

void Duck::setQuckBehavior(QuackBehavior* qb)
{
	quackBehavior = qb;
}

MallardDuck::MallardDuck()
{
	setFlyBehavior(new FlyWithWings);
	setQuckBehavior(new Quack);
}

void MallardDuck::display()
{
	std::cout << "I'm Mallard Duck." << '\n';
}

ModelDuck::ModelDuck()
{
	setFlyBehavior(new FlyNoWay);
	setQuckBehavior(new Quack);
}

void ModelDuck::display()
{
	std::cout << "I'm Model Duck." << '\n';
}