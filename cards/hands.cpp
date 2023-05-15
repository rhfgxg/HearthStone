#include "hands.h"

Hands::Hands() : MAX_SIZE(10)  // 构造函数
{

}

Hands::~Hands()     // 析构函数
{

}

bool Hands::add(Card card)   // 添加卡牌，返回是否添加成功
{
    if(cardss.size() == MAX_SIZE)   // 如果卡牌到达上限
    {
        return false;   // 返回添加失败
    }

    cardss.push_back(card); // 添加卡牌到末尾
    return true;    // 返回添加成功
}

Card Hands::out(int subscript)  // 被拉出
{
    --subscript;    // 消除 下标与 ui的偏差
    Card a = *(cardss.begin()+subscript); // 保存卡牌副本
    cardss.erase(cardss.begin()+subscript); // 删除卡牌

    return a;   // 返回卡牌副本
}

Card Hands::tee_off(int subscript)  // 打出卡牌：结算打出效果，传入在手牌中的下标，返回卡牌对象
{
    --subscript;    // 消除 下标与 ui的偏差
    Card a = *(cardss.begin()+subscript); // 保存卡牌副本
    cardss.erase(cardss.begin()+subscript); // 删除卡牌

    return a;   // 返回卡牌副本
}

Card Hands::return_card(int page)   // 返回指定下标的卡牌
{
    return *(cardss.begin()+page);
}
