#include "cards/venue/hands.h"

#include <QDebug>

// 手牌类
Hands::Hands() : MAX_SIZE(10)  // 构造函数
{

}

Hands::~Hands()     // 析构函数
{

}

bool Hands::add(Card card)   // 添加卡牌，返回是否添加成功
{
    if(cardss.size() == MAX_SIZE)   // 如果手牌数量到达上限
    {
        return false;   // 返回添加失败
    }

    cardss.push_back(card); // 添加卡牌到末尾

    return true;    // 返回添加成功
}

Card Hands::out(int index)  // 被拉出
{
    Card a; // 保存卡牌副本
    if(index != 0)
    {
        --index;    // 消除 下标与 ui的偏差
        a = *(cardss.begin()+index); // 保存卡牌副本
        cardss.erase(cardss.begin()+index); // 删除卡牌
    }
    else
    {
        // ui名字特殊的第 10张牌
        a = *(cardss.begin()+9); // 保存卡牌副本
        cardss.erase(cardss.begin()+9); // 删除卡牌
    }

    return a;   // 返回卡牌副本
}

Card Hands::return_card(int page)   // 返回指定下标的卡牌
{
    return *(cardss.begin()+page);
}

unsigned Hands::size_hands()  // 返回当前手牌数量
{
    return cardss.size();
}
