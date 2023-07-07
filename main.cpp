#include "ui/widget.h"
#include "server/server.h"

#include <QApplication>
#include <QDebug>
#include <QString>
// 数据库相关
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>

void sql_link();
void server();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    sql_link();
//    server();

    Widget w;
    w.show();

    return a.exec();
}

void sql_link()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("HearthStone");
    db.setUserName("root");
    db.setPassword("159357");

    if (!(db.open()))
    {
        qDebug()<<"打开失败："<<db.lastError().text();
    }
}

void server()
{
    Server a;
    QString addr("127.0.0.1");
    int port = 8888;
    a.on_Connect(addr, port);    // 链接:addr是ip，port是端口
    a.on_Send();    // 发送消息
//    a.on_DisConnect();    // 断开链接
}
