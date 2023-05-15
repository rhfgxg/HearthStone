#ifndef COURSE_H
#define COURSE_H

#include "cards/card_set.h" // 牌库类
#include "cards/hands.h"    // 手牌类
#include "course/round.h"   // 回合类

// 游戏进程类

class Course
{
public:
    Course();
    ~Course();

   // 工具函数
    void precedence();  // 确定先后手，先手是 true1

    bool up_rounds();   // 切换回合

    void Start_hands(); // 创建初始手牌

    Hands return_hands1();  // 返回手牌1对象
    Hands return_hands2();  // 返回手牌2对象

private:
    const unsigned MAX_ROUNND; // 最大回合数:90
    unsigned rounds;    // 回合计数器

    bool user;  // 标记用户，true是 user1

    Card_Set card_set_user1;    // 玩家一牌库
    Card_Set card_set_user2;    // 玩家二牌库

    Hands hands1;    // 手牌类1
    Hands hands2;    // 手牌类2

    Round round;    // 回合类
};

#endif // COURSE_H
