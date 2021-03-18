#pragma once
#include "WeaponBehavior.h"

class Character
{
public:
	Character();
	~Character();

	void fight();

	void setWeapon(WeaponBehavior* wb);

private:
	WeaponBehavior* weapon;
};

class Queen : public Character
{
public:
	Queen();
};

class King : public Character
{
public:
	King();
};

class Troll :public Character
{
public:
	Troll();
};

class Knight :public Character
{
public:
	Knight();
};