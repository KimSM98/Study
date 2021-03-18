#include "ForecastDisplay.h"
#include <iostream>
#include <string>

ForecastDisplay::ForecastDisplay(WeatherData* weatherData)
	:mWeatherData(weatherData), mCurrentPressure(29.92f), mLastPressure(0.f)
{
	mWeatherData->registerObserver(this);
}

void ForecastDisplay::update(float temp, float humidity, float pressure)
{
	mLastPressure = mCurrentPressure;
	mCurrentPressure = pressure;

	display();
}

void ForecastDisplay::display()
{
	std::string content = 
		(mCurrentPressure == mLastPressure) ?
		"More of the same" :
		(mCurrentPressure > mLastPressure) ?
		"Improving weather on the way!" : "Watch out for cooler, rainy weather";

	std::cout << "Forecast: " << content << '\n';
}