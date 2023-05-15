#include "cards/card_set.h"

#include <vector>   // 容器
// 数据库相关
#include <QtSql>
#include <QSqlDatabase> // 数据库头文件
#include <QSqlQuery>    // sql查询
#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
#include <QSqlError>    // 处理 sql 报错信息

// 牌库
Card_Set::Card_Set(): MAX_REMAINDER(60), remainder(30), fatigue(0)  // 构造函数
{

    QString cards_id = "root_德鲁伊_aaa";

    // 查询 传入的卡组ID
    if(cards_id == "")    // 检查待查询的是否是空
    {
        qDebug("card_set类：传入 cards_id为空");
    }
    else
    {
        QString str = QString("select * from cards where cards_id = '%1' ").arg(cards_id);
        QSqlQuery query;
        query.exec(str);
//        qDebug() << "card_set类构造函数：cards_id查询结果：" << query.exec(str);    // 返回是否 成功执行查询语句

        while (query.next())
        {
            query.value(0);
//            qDebug() << query.value(0).toString();    // 检测是否找到数据

            for (int i=0; i< 30; ++i)
            {
                // 将查询到的卡牌id保存
                // 用卡牌ID 创建卡牌
                // 将卡牌塞入牌库
                cardss.push_back(Card(query.value(i+3).toString()));
            }
        }

        if(query.value(0) == "")
        {
            QString err = QString("card_set类：cards_id：%1不存在").arg(cards_id);
            qDebug() << err;
        }
    }
}

Card_Set::~Card_Set()    // 析构函数
{

}

void Card_Set::chaos(Card*)  // 打乱卡组
{
    // 传入卡牌数组

    // 打乱数组
}

Card Card_Set::out(QString cardID)    // 移出单张
{
    if (remainder == 0)
    {
        Card card("VAN_GAME_006");
        return card;     // 如果牌库为空，直接结束函数，返回默认卡牌
    }

    QString card_id;
    for(unsigned i=0; i<cardss.size(); ++i) // 遍历牌库
    {
        if(cardID == (*(cardss.begin()+i)).return_id()) // 如果找到目标卡牌
        {
            card_id = (*(cardss.begin()+i)).return_id();    // 获取目标卡牌的ID
            cardss.erase(cardss.begin()+i);     // 删除目标卡牌
        }
    }

    Card card(card_id); // 根据卡牌ID 创建目标卡牌
    return card;    // 返回要移出的卡牌
}

Card Card_Set::draw_out()    // 抽出卡牌
{
    if (remainder == 0) // 如果牌库为空，造成疲劳伤害
    {
        ++fatigue; // 疲劳伤害更新

        Card card("VAN_GAME_006");
        return card;     // 返回默认卡牌
    }

    Card card = *(cardss.begin());  // 创建卡牌副本
    cardss.erase(cardss.begin());     // 删除卡牌

    return card;     // 返回卡牌副本
}

void Card_Set::add(Card card)    // 塞入卡牌
{
    // 如果牌库上限，直接结束函数
    if(remainder >= MAX_REMAINDER)
    {
        return;
    }

    // 塞入卡牌
    cardss.push_back(card);

    ++remainder;// 计数器更新
}
