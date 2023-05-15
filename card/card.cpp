#include "card/card.h"

#include <QDebug>   // 这里的作用是在终端输出信息
// 数据库相关
#include <QtSql>
#include <QSqlDatabase> // 数据库头文件
#include <QSqlQuery>    // sql查询
#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
#include <QSqlError>    // 处理 sql 报错信息

/* card数据库：
 * 0 card_id 卡牌 ID
 * 1 card_name 卡牌名称
 * 2 mana 法力水晶
 * 3 attack 攻击力
 * 4 health 血量
 * 5 career 职业
 * 6 rarity 稀有度
 * 7 card_type 卡牌类型
 *
 * 8 card_description 牌面描述
*/

Card::Card(QString cardId)    // 构造函数，在创建卡组时调用
{
    if(cardId == "")    // 检查待查询的是否是空
    {
        qDebug("card类：传入 card_id为空");
    }
    else
    {
        // 查询数据语法
        // QString("select 字段名 from 表名 where 条件列表 ").arg(变量)
        // 字段名用 * 表示所有字段
        QString str = QString("select * from card where card_id = '%1' ").arg(cardId);
        QSqlQuery query;
        query.exec(str);
//        qDebug() << "card类构造函数：card_id查询结果：" << query.exec(str);    // 返回是否 成功执行查询语句

        while (query.next())
        {
            card_id = query.value(0).toString();    // 初始化卡牌ID
            card_name = query.value(1).toString();  // 初始化卡牌名

            mana = query.value(2).toInt();      // 初始化法力水晶
            attack = query.value(3).toInt();    // 初始化攻击力
            health = query.value(4).toInt();    // 初始化血量

            card_type = query.value(5).toString();     // 初始化卡牌类型
            rarity = query.value(6).toString();     // 初始化稀有度
            career = query.value(7).toString();     // 初始化职业

//            keyword   // 初始化关键词
            card_description = query.value(8).toString();    // 初始化卡牌描述

//            qDebug() << card_id << card_name << mana << attack << health << card_type << rarity << career << card_description;
        }

        if(query.value(0) == "")
        {
            QString err = QString("card类：card_id：%1不存在").arg(cardId);
            qDebug() << err;
        }
    }
}

void Card::mana_update(int update)     // 费用更新
{
    /* 数据不能复原，不需要保存原始数据 */
    mana += update;
}

QString Card::return_id()   // 返回卡牌ID
{
    return card_id;
}

QString Card::return_name()  // 返回名称
{
    return card_name;
}

int Card::return_mana()      // 返回费用
{
    return mana;
}

int Card::return_attack()   // 返回攻击力
{
    return attack;
}

int Card::return_health()   // 返回血量
{
    return health;
}

QString Card::return_type()      // 返回卡牌类型
{
    return card_type;
}

QString Card::return_rarity()// 返回稀有度
{
    return rarity;
}

QString Card::return_career()   // 返回职业
{
    return career;
}

QString Card::return_desc()     // 返回卡牌描述
{
    return card_description;
}

void Card::update_desc(QString desc)     // 修改卡牌描述
{
    card_description = desc;
}
