#ifndef CARD_H
#define CARD_H

#include "keyword.h"
#include "rarity.h"
#include <QString>

namespace hs { class Card; }


class Card   // 卡牌
{
public:
    Card(QString card_id);    // 传入 card_id 查询卡牌所有信息，创建对象
    void mana_update(int update);     // 费用更新
    void choose_min();  // 选择随从目标，接受传入的界面位置的对象
    void choose_her();  // 选择攻击英雄，传入对方英雄
    void random();      // 随机目标，生成随机位置，然后传入


private:
    QString card_id;   // 卡牌id
    QString card_name;     // 卡牌名称
    int mana;   // 法力水晶
    Keyword keyword;    // 关键词
    Rarity rarity;  // 稀有度;
    QString career;    // 职业
    QString Expansion_packs;   // 扩展包
    QString Artist;    // 画师
    QString card_description;  // 牌面描述
};

#endif // CARD_H
