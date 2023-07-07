#include "cards/cards.h"

#include <QDebug>   // 这里的作用是在终端输出信息
// 数据库相关
#include <QtSql>
#include <QSqlDatabase> // 数据库头文件
#include <QSqlQuery>    // sql查询
#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
#include <QSqlError>    // 处理 sql 报错信息

// 卡组类

Cards::Cards() : MAX_SIZE(30)     // 创建卡组
{

}

Cards::~Cards()
{

}

void Cards::all_out() // 清空卡组
{
    cardss.clear(); // 清空容器，不回收内存
}

void Cards::dele()   // 删除卡组
{
    // 删除数据库中的数据
    QString cards_id = "aaa";
    if(cards_id ==  "")
    {
        qDebug("卡组类析构函数：卡组ID为空");
    }

    else
    {
        // 从数据库中查询是否有目标数据
        QSqlQuery query;

        QString temp = QString("select * from cards where cards_id = '%1'").arg(cards_id);
        query.exec(temp);

        QString deletename;
        while (query.next())
        {
            deletename = query.value(0).toString();
        }
        if(deletename == "")
        {
            QString a = QString("%1不存在，删除失败").arg(cards_id);
            qDebug() << a;
        }
        else
        {
            QString str =  QString("delete from cards where cards_id = '%1'").arg(cards_id);
            query.exec(str);//删除信息
        }
    }
}

void Cards::get(Card card)     // 添加单张
{
    if (cardss.size() == MAX_SIZE)  // 如果卡组到达上限
    {
        return; // 添加失败
    }

    // 检测卡牌是否是传说
    if(card.return_rarity() == "传说" || card.return_rarity() == "金色传说")
    {
        // 如果是：检查卡组中是否有相同牌，有则不放入并报错
        for(unsigned i=0; i<cardss.size(); ++i)
        {
            if((cardss.begin()+i)->return_id() == card.return_id())
            {
                qDebug("有相同卡牌");
                // 弹窗，结束函数
                return;
            }
        }
    }
    else
    {
        // 如果不是传说，检查是否存在两张相同牌
        for(unsigned i=0; i<cardss.size(); ++i)
        {
            if((cardss.begin()+i)->return_id() == card.return_id())
            {
                for(unsigned j=i+1; j<cardss.size(); ++j)   // 从当前位置向后找，是否有相同卡牌
                {
                    if((cardss.begin()+j)->return_id() == card.return_id())
                    {
                        qDebug("有相同卡牌");
                        // 弹窗，结束函数
                        return;
                    }
                }
            }
        }
    }

    cardss.push_back(card);  // 插入卡牌

}

void Cards::out(int index)    // 移出单张
{
    if (cardss.size() == 0) // 如果牌库为空，结束函数
    {
        return;
    }
    else
    {
        cardss.erase(cardss.begin()+index);     // 删除对应下标的卡牌
    }
}

void Cards::new_id()     // 生成ID
{
    // 创建ID
    cards_id = "id:" + career + "_" + cards_name + "_user";

    // 假设id不会重复
//    // 查看是否有相同ID
//    QString str = QString("select * from cards where cards_id = '%1'").arg(cards_id);
//    QSqlQuery query;
//    query.exec(str);

//    QString a;
//    while (query.next())
//    {
//        a = query.value(0).toString();
//    }

//    if(a == "")
//    {
//        // id 生成成功
//    }
}

void Cards::update_name(QString name)  // 设置卡组名
{
    cards_name = name;
}

void Cards::update_career(QString cards_career)   // 设置职业
{
    career = cards_career;
}

QString Cards::return_id()    // 返回卡组ID
{
    return cards_id;
}

QString Cards::return_career()  // 返回职业
{
    return career;
}

int Cards::size_cards()     // 返回卡组现有卡牌数量
{
    return cardss.size();
}

void Cards::save()   // 将卡组存入数据库
{
    new_id();   // 生成卡组ID

    QSqlQuery query;
    // 插入
    QString str = QString("insert into cards"
                          "values"
                          "("
                          "'%1', '%2', '%3', "
                          "'%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', "
                          "'%14', '%15', '%16', '%17', '%18', '%19', '%20', '%21', '%22', '%23', "
                          "'%24', '%25', '%26', '%27', '%28', '%29', '%30', '%31', '32%', '33%'"
                          ")")
                    .arg(cards_id, cards_name, career)
                    .arg((*(cardss.begin()+0)).return_id(), (*(cardss.begin()+1)).return_id())
                    .arg((*(cardss.begin()+2)).return_id(), (*(cardss.begin()+3)).return_id())
                    .arg((*(cardss.begin()+4)).return_id(), (*(cardss.begin()+5)).return_id())
                    .arg((*(cardss.begin()+6)).return_id(), (*(cardss.begin()+7)).return_id())
                    .arg((*(cardss.begin()+8)).return_id(), (*(cardss.begin()+9)).return_id())
                    .arg((*(cardss.begin()+10)).return_id(),(*(cardss.begin()+11)).return_id())
                    .arg((*(cardss.begin()+12)).return_id(), (*(cardss.begin()+13)).return_id())
                    .arg((*(cardss.begin()+14)).return_id(), (*(cardss.begin()+15)).return_id())
                    .arg((*(cardss.begin()+16)).return_id(), (*(cardss.begin()+17)).return_id())
                    .arg((*(cardss.begin()+18)).return_id(), (*(cardss.begin()+19)).return_id())
                    .arg((*(cardss.begin()+20)).return_id(), (*(cardss.begin()+21)).return_id())
                    .arg((*(cardss.begin()+22)).return_id(), (*(cardss.begin()+23)).return_id())
                    .arg((*(cardss.begin()+24)).return_id(), (*(cardss.begin()+25)).return_id())
                    .arg((*(cardss.begin()+26)).return_id(), (*(cardss.begin()+27)).return_id())
                    .arg((*(cardss.begin()+28)).return_id(), (*(cardss.begin()+29)).return_id());
    query.exec(str); //执行插入操作
}

