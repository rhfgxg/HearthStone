#ifndef DISCARD_H
#define DISCARD_H

#include "card/card.h"

#include <vector>

// 弃牌区
class Discard
{
public:
    Discard();

    void add(Card card);    // 弃牌

private:
    std::vector<Card> cardss;   // 保存丢弃的牌
};

#endif // DISCARD_H
