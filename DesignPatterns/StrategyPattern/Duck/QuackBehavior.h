#pragma once
#include <iostream>

class QuackBehavior
{
public:
	virtual void quack();
};

class Quack : public QuackBehavior
{
public:
	void quack();
};

class MuteQuack : public QuackBehavior
{
	void quack();
};

class Squeak : public QuackBehavior
{
	void quack();
};