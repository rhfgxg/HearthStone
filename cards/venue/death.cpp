#include "death.h"

// 坟场

Death::Death()
{

}

void Death::add_minion()  // 随从死亡
{

}

void Death::add_weapon()  // 武器死亡
{

}

void Death::add_spell()   // 法术使用
{

}

Card Death::return_minion()   // 返回随从
{
    // 返回一个随机数：范围0-容器长度
    unsigned random = 0;

    return *(weapon.begin()+random);
}

Card Death::return_weapon()   // 返回武器
{
    unsigned random = 0;

    return *(minion.begin()+random);
}

Card Death::return_spell()    // 返回法术
{
    unsigned random = 0;

    return *(spell.begin()+random);
}
