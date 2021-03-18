#include "WeaponBehavior.h"
#include <iostream>

void WeaponBehavior::useWeapon()
{
	std::cout << "Base Weapon" << '\n';
}

void KnifeBehavior::useWeapon()
{
	std::cout << "Knife Attack!" << '\n';
}

void BowAndArrowBehavior::useWeapon()
{
	std::cout << "Arrow Attack!" << '\n';
}

void AxeBehavior::useWeapon()
{
	std::cout << "Axe Attack!" << '\n';
}

void SwordBehavior::useWeapon()
{
	std::cout << "Sword Attack!" << '\n';
}