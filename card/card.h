#ifndef CARD_H
#define CARD_H

#include "module/keyword.h"

#include <QString>

class Card   // 卡牌
{
public:
    Card(QString card_id);    // 传入 card_id 查询卡牌所有信息，创建对象
    void mana_update(int update);     // 费用更新

    QString return_id();    // 返回ID
    QString return_name();  // 返回名称

    int return_mana();      // 返回费用
    int return_attack();    // 返回攻击力
    int return_health();    // 返回血量

    QString return_type();      // 返回卡牌类型
    QString return_rarity();    // 返回稀有度
    QString return_career();    // 返回职业

    QString return_desc();      // 返回卡牌描述
    void update_desc(QString desc);     // 修改卡牌描述

private:
    QString card_id;   // 卡牌id
    QString card_name;     // 卡牌名称

    int mana;   // 法力水晶
    int attack; // 攻击力
    int health; // 返回血量

    QString card_type;  // 卡牌类型
    QString rarity;  // 稀有度;
    QString career;    // 职业

    Keyword keyword;    // 关键词
    QString card_description;  // 牌面描述
};

#endif // CARD_H
