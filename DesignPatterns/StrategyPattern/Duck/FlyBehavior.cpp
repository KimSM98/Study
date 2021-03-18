#include "FlyBehavior.h"
#include <iostream>

void FlyBehavior::fly()
{
	std::cout << "Default fly" << '\n';
}
void FlyWithWings::fly()
{
	std::cout << "I'm flying!" << '\n';
}

void FlyNoWay::fly()
{
	std::cout << "I can't fly..." << '\n';
}

void FlyRocketPowered::fly()
{
	std::cout << "I'm flying with a rocket" << '\n';
}