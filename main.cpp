 #include "ui/widget.h"
//#include "card/card.h"
#include <QApplication>

#include <QDebug>   // 这里的作用是在终端输出信息
#include <QString>

// 数据库相关
#include <QtSql>
#include <QSqlDatabase> // 数据库头文件
#include <QSqlQuery>    // sql查询
#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
#include <QSqlError>    // 处理 sql 报错信息

void sql_link();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);     // 软件生命进程

    sql_link();     // 连接数据库

    Widget w;       // UI界面
    w.show();

    return a.exec();
}

void sql_link()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");  // 连接本地主机
    db.setPort(3306);   // 端口
    db.setDatabaseName("HearthStone");    // 数据库名称
    db.setUserName("root");    // 登陆数据库的用户名
    db.setPassword("159357");   // 登陆数据库的用户密码

    bool ok = db.open();    // ·获取是否打开
    if (ok)
    {

    }
    else
    {
        qDebug()<<"打开失败："<<db.lastError().text(); // 返回数据库报错的原因
    }
}
