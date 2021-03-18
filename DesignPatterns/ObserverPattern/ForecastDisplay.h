#pragma once
#include "Observer.h"
#include "DisplayElement.h"
#include "WeatherData.h"

class ForecastDisplay : public Observer, DisplayElement
{
public:
	ForecastDisplay(WeatherData* weatherData);

	void update(float temp, float humidity, float pressure) override;
	void display() override;

private:
	float mCurrentPressure = 29.92f;
	float mLastPressure;

	WeatherData* mWeatherData;
};