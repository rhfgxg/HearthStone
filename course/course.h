#ifndef COURSE_H
#define COURSE_H

#include "cards/venue/card_set.h"   // 牌库类
#include "cards/venue/death.h"  // 坟场
#include "cards/venue/discard.h"    // 弃牌区
#include "cards/venue/hands.h"  // 手牌类
#include "cards/venue/venue.h"  // 战场类

// 游戏进程类
class Course
{
public:
    Course();
    ~Course();

    void precedence();  // 确定先后手，先手是 true1
    void Start_hands(); // 创建初始手牌

    bool up_rounds();   // 切换回合
    void begin_round1();  // user1回合开始
    void begin_round2();  // user2回合开始
    void end_round1();   // user1回合结束
    void end_round2();   // user2回合结束

    bool return_user(); // 返回当前回合玩家：true为 user1

    unsigned return_mana1(); // 返回 user1剩余法力水晶
    unsigned return_mana2(); // 返回 user2剩余法力水晶
    unsigned return_Max_mana1(); // 返回 user1当前最大法力水晶
    unsigned return_Max_mana2(); // 返回 user2当前最大法力水晶

    Card_Set return_card_set1();    // 返回 user1牌库对象
    Card_Set return_card_set2();    // 返回 user2牌库对象

    Hands return_hands1();  // 返回 user1手牌对象
    Hands return_hands2();  // 返回 user2手牌对象

    Venue return_venue1();  // 返回 user1随从
    Venue return_venue2();  // 返回 user2随从

    Death return_death1();  // user1坟场
    Death return_death2();  // user2坟场

    Discard return_discard1(); // user1弃牌区
    Discard return_discard2(); // user2弃牌区

private:
    const unsigned MAX_ROUNND; // 最大回合数:45
    unsigned rounds;    // 回合计数器
    const unsigned MAX_MANA;  // 法力水晶上限：10
    unsigned mana1;  // user1法力水晶
    unsigned mana2;  // user2法力水晶
    unsigned Max_mana1;  // user1当前法力水晶上限
    unsigned Max_mana2;  // user2当前法力水晶上限


    bool user;  // 标记用户，true是 user1

    Card_Set card_set1;    // user1牌库
    Card_Set card_set2;    // user2牌库

    Hands hands1;    // user1手牌
    Hands hands2;    // user2手牌

    Venue venue1;  // user1随从
    Venue venue2;  // user2随从

    Death death1;  // user1坟场
    Death death2;  // user2坟场

    Discard discard1; // user1弃牌区
    Discard discard2; // user2弃牌区
};

#endif // COURSE_H
