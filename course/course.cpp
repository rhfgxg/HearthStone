#include "course.h"
// 游戏进程

Course::Course() : MAX_ROUNND(45)   // 构造函数
{
    // 由 UI “对战模式”创建
    // 结束游戏时，退出“对战模式”

    user = true;    // 区分用户

    // 默认初始化玩家1牌库
    // 默认初始化玩家2牌库

    // 默认初始化手牌类1
    // 默认初始化手牌类2

    Start_hands();  // 创建双方初始手牌

    // 默认初始化回合
    rounds = 1;     // 初始化回合计数器
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
    // 对局开始，抽三张牌
    for(int i=0; i<3; ++i)
    {
        hands1.add(card_set_user1.draw_out());  // 将抽出的牌加入手牌
    }
    // 对局开始，抽四张牌
    for(int i=0; i<4; ++i)
    {
        hands2.add(card_set_user2.draw_out());  // 将抽出的牌加入手牌
    }
}

bool Course::up_rounds()  // 切换回合
{
    round.end_round();    // 结算回合结束

    if(rounds == MAX_ROUNND)     // 如果回合数上限
    {
        // 结束游戏
        // 平局
        return false;   // 返回切换失败
    }

    round.start_round();  // 结算回合开始

    ++rounds;   // 回合计数器更新
    // 切换回合用户
    return true;    // 返回切换成功
}

Hands Course::return_hands1()  // 返回手牌1对象
{
    return hands1;
}

Hands Course::return_hands2()  // 返回手牌2对象
{
    return hands2;
}

