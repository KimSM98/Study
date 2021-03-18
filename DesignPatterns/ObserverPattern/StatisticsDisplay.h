#pragma once
#include "Observer.h"
#include "DisplayElement.h"
#include "WeatherData.h"

class StatisticsDisplay : public Observer, DisplayElement
{
public:
	StatisticsDisplay(WeatherData* weaterData);
	void update(float temp, float humidity, float pressure) override;
	void display() override;

private:
	float mMaxTemp = 0.f;
	float mMinTemp = 200.f;
	float mTempSum = 0.f;
	int mNumReadings;

	class WeatherData* mWeatherData;
};
