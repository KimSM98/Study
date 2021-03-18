#include "WeatherData.h"
#include "Observer.h"

WeatherData::WeatherData()
	:mTemperature(0.f), mHumidity(0.f), mPressure(0.f)
{
}

void WeatherData::registerObserver(Observer* o)
{
	mObservers.emplace_back(o);
}

void WeatherData::removeObserver(Observer* o)
{
	auto iter = std::find(mObservers.begin(), mObservers.end(), o);

	for (; iter != mObservers.end(); ++iter)
	{
		std::iter_swap(iter, mObservers.end() - 1);
		mObservers.pop_back();
	}

}

void WeatherData::notifyObservers()
{
	for (auto iter = mObservers.begin(); iter!= mObservers.end(); ++iter)
	{
		(*iter)->update(mTemperature, mHumidity, mPressure);
	}
}

void WeatherData::measurementsChanged()
{
	notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
	mTemperature = temperature;
	mHumidity = humidity;
	mPressure = pressure;
	measurementsChanged();
}