// DesignPatternStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Duck.h"
#include "QuackBehavior.h"
#include "FlyBehavior.h"

using namespace std;

int main()
{
    Duck* mallard = new MallardDuck();
    mallard->performQuack();
    mallard->performFly();

    Duck* model = new ModelDuck();
    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered);
    model->performFly();

    delete mallard;
    delete model;

    return 0;
}
