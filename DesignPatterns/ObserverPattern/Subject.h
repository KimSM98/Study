#pragma once

class Subject
{
public:
	virtual void registerObserver(class Observer* o) {};
	virtual void removeObserver(class Observer* o) {};
	virtual void notifyObservers() {};
};
