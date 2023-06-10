#ifndef VENUE_H
#define VENUE_H

#include "card/card.h"
#include <vector>   // 容器

// 战场
class Venue
{
public:
    Venue();
    void add(Card card);    // 打出随从
    void out(); // 移除随从

    unsigned size_venue();    // 返回随从数量
    Card return_minion(unsigned subscript);   // 返回指定随从

private:
    std::vector<Card> cardss;   // 随从表
    const unsigned SIZE;
};

#endif // VENUE_H
