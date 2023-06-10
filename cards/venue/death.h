#ifndef DEATH_H
#define DEATH_H

#include "card/card.h"

#include <vector>
// 坟场
class Death
{
public:
    Death();
    void add_minion();  // 随从死亡
    void add_weapon();  // 武器死亡
    void add_spell();   // 法术使用

    Card return_minion();   // 返回随从
    Card return_weapon();   // 返回武器
    Card return_spell();    // 返回法术

private:
    std::vector<Card> minion;   // 死亡随从
    std::vector<Card> weapon;   // 武器
    std::vector<Card> spell;    // 法术
};

#endif // DEATH_H
