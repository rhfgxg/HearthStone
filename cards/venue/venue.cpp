#include "venue.h"

// 战场
Venue::Venue():
    SIZE(7)
{

}

void Venue::add(Card card)  // 随从入场：打出，召唤
{
    cardss.push_back(card);
}

void Venue::out()   // 随从离场：死亡，移回
{

}

unsigned Venue::size_venue()  // 返回随从数量
{
    return cardss.size();
}

Card Venue::return_minion(unsigned subscript)   // 返回指定随从
{
    return *(cardss.begin()+subscript);
}
