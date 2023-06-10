#include "discard.h"

// 弃牌区
Discard::Discard()
{

}

void Discard::add(Card card)    // 弃牌
{
    cardss.push_back(card);
}
