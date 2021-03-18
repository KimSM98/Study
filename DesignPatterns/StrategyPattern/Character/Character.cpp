#include "Character.h"
#include <iostream>

Character::Character()
{
	weapon = new WeaponBehavior();
}

Character::~Character()
{
	delete weapon;
	std::cout << "Character Destructor" << '\n';
}

void Character::fight()
{
	weapon->useWeapon();
}

void Character::setWeapon(WeaponBehavior* wb)
{
	weapon = wb;
}

Queen::Queen()
{
	setWeapon(new BowAndArrowBehavior);
}

King::King()
{
	setWeapon(new KnifeBehavior);
}

Troll::Troll()
{
	setWeapon(new AxeBehavior);
}

Knight::Knight()
{
	setWeapon(new SwordBehavior);
}


