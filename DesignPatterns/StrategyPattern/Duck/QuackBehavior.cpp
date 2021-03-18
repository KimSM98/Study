#include "QuackBehavior.h"
#include <iostream>

void QuackBehavior::quack()
{
	std::cout << "Default quack" << '\n';
}

void Quack::quack()
{
	std::cout << "Quack!" << '\n';
}

void MuteQuack::quack()
{
	std::cout << "..." << '\n';
}

void Squeak::quack()
{
	std::cout << "peep!" << '\n';
}