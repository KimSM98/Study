#include "CurrentConditionsDisplay.h"
#include <iostream>

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject* weatherData)
	:mWeatherData(weatherData), mTemperature(0.f), mHumidity(0.f)
{
	mWeatherData->registerObserver(this);
}

void CurrentConditionsDisplay::update(float temperature, float humidity, float pressure)
{
	mTemperature = temperature;
	mHumidity = humidity;
	display();
}

void CurrentConditionsDisplay::display()
{
	std::cout << "Current conditions: " << mTemperature << "F degreees and " << mHumidity << "% humidity" << '\n';
}