#ifndef CARDS_H
#define CARDS_H

#include "card/card.h"

#include <vector>
#include <QString>

class Cards     // 卡组
{
public:
    Cards();    // 构造函数
    ~Cards();   // 析构函数

    void all_out(); // 清空卡组
    void dele();    // 删除卡组

    void get(Card card);     // 添加单张，传入要添加的卡牌
    void out(int index);     // 移出单张，传入目标卡牌的下标

    void new_id();  // 生成卡组id

    void update_name(QString name);  // 设置卡组名
    void update_career(QString cards_career);   // 设置职业

    QString return_id();    // 返回卡组ID
    int  size_cards();   // 返回卡组现有卡牌数量
    QString return_career();    // 返回职业

    void save();    // 将卡组存入数据库

private:
    QString cards_id;       // 卡组id
    QString cards_name;     // 卡组名
    QString career;         // 职业

    std::vector<Card> cardss;   // 卡牌数组
    const unsigned MAX_SIZE;    // 最多保存 30 张牌
};
#endif // CARDS_H
