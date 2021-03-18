#pragma once
#include "Subject.h"
#include <vector>

class WeatherData : public Subject
{
public:
	WeatherData();

	void registerObserver(class Observer* o) override;
	void removeObserver(class Observer* o) override;
	void notifyObservers() override;
	
	void measurementsChanged();
	void setMeasurements(float temperature, float humidity, float pressure);

private:
	std::vector<class Observer*> mObservers;
	float mTemperature;
	float mHumidity;
	float mPressure;
};
