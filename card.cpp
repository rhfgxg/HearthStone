#include "card.h"

#include <QDebug>   // 这里的作用是在终端输出信息
// #include <QString>   // 在 card.h中包含

// 数据库相关
#include <QtSql>
#include <QSqlDatabase> // 数据库头文件
#include <QSqlQuery>    // sql查询
#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
#include <QSqlError>    // 处理 sql 报错信息

/* card数据库：
 * 0 card_id 卡牌 ID
 * 1 card_name 卡牌名称
 *
 * 2 mana 法力水晶
 * 3 attack 攻击力
 * 4 health 血量
 *
 * 5 career 职业
 * 6 rarity 稀有度
 * 7 card_type 卡牌类型
 *
 * 8 card_description 牌面描述
*/

Card::Card(QString card_id)    // 构造函数，在创建卡组时调用
{
    if(card_id == "")    // 检查待查询的是否是空
    {
        qDebug("card类：传入 card_id为空");
    }
    else
    {
        // 查询数据语法
        // QString("select 字段名 from 表名 where 条件列表 ").arg(变量)
        // 字段名用 * 表示所有字段
        QString str = QString("select * from card where card_id = '%1' ").arg(card_id);
        QSqlQuery query;
        qDebug() << "card类：card_id查询结果：" << query.exec(str);    // 返回是否 成功执行查询语句

        while (query.next())
        {
            query.value(0);
        }
        if(query.value(0) == "")
        {
            QString err = QString("card类：card_id：%1不存在").arg(card_id);
            qDebug() << err;
        }
        else
        {
            this->mana = query.value(2).toInt();   // 法力水晶
        }
    }
}

void Card::mana_update(int update)     // 费用更新
{
    /* 数据不能复原，不需要保存原始数据 */
    mana += update;
}

void Card::choose_min()  // 选择随从目标
{

}

void Card::choose_her()  // 选择攻击英雄
{

}

void Card::random()      // 随机目标
{

}
