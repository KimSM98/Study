#pragma once
#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"

class CurrentConditionsDisplay : public Observer, DisplayElement
{
public:
	CurrentConditionsDisplay(Subject* weatherData);

	void update(float temperature, float humidity, float pressure) override;
	void display() override;

private:
	float mTemperature;
	float mHumidity;
	Subject* mWeatherData;
};
