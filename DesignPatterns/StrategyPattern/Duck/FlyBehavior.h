#pragma once

class FlyBehavior
{
public:
	virtual void fly();
};

class FlyWithWings : public FlyBehavior
{
public:
	void fly();
};

class FlyNoWay : public FlyBehavior
{
public:
	void fly();
};

class FlyRocketPowered : public FlyBehavior
{
public:
	void fly();
};
