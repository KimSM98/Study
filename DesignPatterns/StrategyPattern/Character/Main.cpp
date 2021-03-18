// DesignPatternStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Character.h"

using namespace std;

int main()
{
    Character* queen = new Queen();

    queen->fight();
    queen->setWeapon(new AxeBehavior);
    queen->fight();
    
    Character* knight = new Knight();

    knight->fight();

    return 0;
}
