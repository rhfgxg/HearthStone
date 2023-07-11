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

Server a;

void sql_link();
void server_link();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    sql_link();
    server_link();

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

void server_link()
{
    QString addr("127.0.1.1");
    int port = 8888;
    a.on_Connect(addr, port);    // 链接:addr是ip，port是端口
}
