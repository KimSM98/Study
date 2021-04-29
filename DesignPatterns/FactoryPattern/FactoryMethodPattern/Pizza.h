#pragma once
#include <string>
#include <vector>

using namespace std;

class Pizza
{
public:
	Pizza() {};
	~Pizza() { delete this; }

	void prepare();
	void bake();
	virtual void cut();
	void box();

	string getName() const;

protected:
	string mName;
	string mDough;
	string mSauce;

	vector<string> mToppings;
};
