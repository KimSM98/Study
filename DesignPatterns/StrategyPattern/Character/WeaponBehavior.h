#pragma once

class WeaponBehavior
{
public:
	virtual void useWeapon();
};

class KnifeBehavior : public WeaponBehavior
{
public:
	void useWeapon();
};

class BowAndArrowBehavior : public WeaponBehavior
{
public:
	void useWeapon();
};

class AxeBehavior : public WeaponBehavior
{
public:
	void useWeapon();
};

class SwordBehavior : public WeaponBehavior
{
public:
	void useWeapon();
};