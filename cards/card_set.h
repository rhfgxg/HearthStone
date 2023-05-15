#ifndef CARD_SET_H
#define CARD_SET_H

#include "card/card.h"

class Card_Set  // 牌库
{
public:
    Card_Set();     // 构造函数
    ~Card_Set();    // 析构函数

    void chaos(Card*);   // 打乱卡组

    Card out(QString cardID);     // 移出单张
    Card draw_out();    // 抽出卡牌

    void add(Card card);     // 塞入单张

private:
    std::vector<Card> cardss;   // 卡牌数组
    const unsigned MAX_REMAINDER;    // 牌库上限
    unsigned remainder;  // 剩余卡牌
    unsigned fatigue;    // 疲劳伤害


};

#endif // CARD_SET_H
