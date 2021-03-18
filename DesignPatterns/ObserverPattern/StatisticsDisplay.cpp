#include "StatisticsDisplay.h"
#include <iostream>

StatisticsDisplay::StatisticsDisplay(WeatherData* weaterData)
	:mWeatherData(weaterData), mNumReadings(0)
{
	mWeatherData->registerObserver(this);
}

void StatisticsDisplay::update(float temp, float humidity, float pressure)
{
	mTempSum += temp;
	mNumReadings++;

	if (temp > mMaxTemp)
	{
		mMaxTemp = temp;
	}
	if (temp < mMinTemp)
	{
		mMinTemp = temp;
	}

	display();
}

void StatisticsDisplay::display()
{
	std::cout << "Avg/Max/Min temperature = " << (mTempSum / mNumReadings) << '/' << mMaxTemp << '/' << mMinTemp << '\n';
}