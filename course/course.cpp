#include "course/course.h"
// 游戏进程

Course::Course() : MAX_ROUNND(45), MAX_MANA(10)   // 构造函数
{
    // 由 UI “对战模式”创建
    // 结束游戏时，退出“对战模式”

    user = true;    // 区分用户

    // 默认初始化玩家1牌库
    // 默认初始化玩家2牌库

    // 默认初始化手牌类1
    // 默认初始化手牌类2

    Start_hands();  // 创建双方初始手牌
    // 跳过选牌
    begin_round1(); // user1回合开始

    // 默认初始化回合
    rounds = 1;     // 初始化回合计数器
    mana1 = 1;   // 剩余法力水晶
    mana2 = 0;
    Max_mana1 = 1;   // 当前最大法力水晶
    Max_mana2 = 0;
}

Course::~Course()   // 析构函数
{

}

void Course::precedence()   // 确定先后手，先手是 true1
{
    // 随机数：1 2
}
void Course::Start_hands()  // 创建初始手牌
{
    // user1 对局开始，抽三张牌
    for(int i=0; i<3; ++i)
    {
        hands1.add(card_set1.draw_out());  // 将抽出的牌加入手牌
    }
    // user2 对局开始，抽四张牌
    for(int i=0; i<4; ++i)
    {
        hands2.add(card_set2.draw_out());  // 将抽出的牌加入手牌
    }
    hands2.add(Card("GAME_005"));    // 后手给硬币
}

bool Course::up_rounds()  // 切换回合
{
    if(rounds == MAX_ROUNND)     // 如果回合数上限
    {
        // 结束游戏
        // 平局
        return false;   // 返回切换失败
    }

    ++rounds;   // 回合计数器更新

    if(user)    // 如果当前玩家是 user1
    {
        user = false;   // 玩家切换为 user2
        // 结算 user2的回合开始
        begin_round2();   // user2 回合开始
        // 法力水晶
        if(Max_mana2 != MAX_MANA)
        {
            // 如果法力水晶没有到上限，更新最大计数器
            ++Max_mana2;
        }
        mana2 = Max_mana2;    // 恢复满法力水晶
    }
    else
    {
        user = true;    // 玩家切换为 user1
        // 结算 user1的回合开始
        begin_round1();   // user1 回合开始
        // 法力水晶
        if(Max_mana1 != MAX_MANA)
        {
            // 如果法力水晶没有到上限，更新最大计数器
            ++Max_mana1;
        }
        mana1 = Max_mana1;    // 恢复满法力水晶
    }

    return true;    // 返回切换成功
}
void Course::begin_round1()  // user1 回合开始
{
// 抽牌阶段
    Card card = card_set1.draw_out();  // 抽牌
    // 发出抽牌信号，以结算抽牌效果
    hands1.add(card);  // 将抽出的牌加入手牌
    // 结算

}
void Course::begin_round2()  // user2 回合开始
{
// 抽牌阶段
    Card card = card_set2.draw_out();  // 抽牌
    // 发出抽牌信号，以结算抽牌效果
    hands2.add(card);  // 将抽出的牌加入手牌
    // 结算

}
void Course::end_round1()   // 回合结束
{

}

/***************************************** 数据成员对外接口 *************************************/
bool Course::return_user()  // 当前回合玩家：true为 user1
{
    return user;
}

unsigned Course::return_mana1() // user1剩余法力水晶
{
    return mana1;
}
unsigned Course::return_mana2() // user2剩余法力水晶
{
    return mana2;
}

unsigned Course::return_Max_mana1() // user1当前最大法力水晶
{
    return Max_mana1;
}
unsigned Course::return_Max_mana2() // user2当前最大法力水晶
{
    return Max_mana2;
}

Card_Set Course::return_card_set1()    // user1牌库
{
    return card_set1;
}
Card_Set Course::return_card_set2()    // user2牌库
{
    return card_set2;
}

Hands Course::return_hands1()  // user1手牌对象
{
    return hands1;
}
Hands Course::return_hands2()  // user2手牌对象
{
    return hands2;
}

Venue Course::return_venue1() // user1随从
{
    return venue1;
}
Venue Course::return_venue2()  // user2随从
{
    return venue2;
}

Death Course::return_death1()  // user1坟场
{
    return death1;
}
Death Course::return_death2()  // user2坟场
{
    return death2;
}

Discard Course::return_discard1() // user1弃牌区
{
    return discard1;
}
Discard Course::return_discard2() // user2弃牌区
{
    return discard2;
}

