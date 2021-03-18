// DesignPatternStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "StatisticsDisplay.h"
#include "ForecastDisplay.h"

using namespace std;

int main()
{
    WeatherData* weatherData = new WeatherData();

    CurrentConditionsDisplay currentDisplay(weatherData);
    StatisticsDisplay statisticsDisplay(weatherData);
    ForecastDisplay forecastDisplay(weatherData);

    cout << fixed << cout.precision(1);

    weatherData->setMeasurements(80.f, 65.f, 30.4f);
    weatherData->setMeasurements(82.f, 70.f, 29.2f);
    weatherData->setMeasurements(78.f, 90.f, 29.2f);

    delete weatherData;

    return 0;
}
