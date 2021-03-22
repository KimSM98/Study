#pragma once
#include <string>

using namespace std;

class Beverage
{
public:
	virtual string getDescription() const { return mDescription; }
	virtual double cost() const = 0;

protected:
	string mDescription = "--";
};