#ifndef HANDS_H
#define HANDS_H

#include "card/card.h"  // 卡牌类

#include <vector>   // 容器

// 手牌类
class Hands
{
public:
    Hands();    // 构造函数
    ~Hands();   // 析构函数

    bool add(Card card); // 添加卡牌，返回是否添加成功
    Card out(int subscript); // 被拉出，传入下标，返回卡牌
    Card tee_off(int subscript);  // 打出卡牌,传入在手牌中的下标，返回卡牌对象，结算打出效果

    Card return_card(int page); // 返回指定下标的卡牌
private:
    std::vector<Card> cardss;   // 卡牌容器
    const unsigned MAX_SIZE;    // 最多 10 张牌

};

#endif // HANDS_H
