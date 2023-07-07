#include "user/user.h"

// 数据库相关
#include <QtSql>
#include <QSqlDatabase> // 数据库头文件
#include <QSqlQuery>    // sql查询
#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
#include <QSqlError>    // 处理 sql 报错信息


User::User()
{
    // 初始化为空
    // 通过接口访问数据库
    // 创建用户后，保存到数据库
    // 登录时获取到用户数据进行赋值
    user_name = NULL;
    user_id = NULL;
    user_password = NULL;
}

bool User::enroll(QString account, QString name, QString password)   // 用户注册：返回 0成功，1账号错误
{
    // 创建用户ID
    user_id = "root";
    // 账号，用户名，密码
    user_account = account;
    user_name = name;
    user_password = password;   // 123456：e10adc3949ba59abbe56e057f20f883e
    // 金币，粉尘
    int coins = 0;
    int card_splinter = 0;

    // 插入数据库
    QString str = QString("insert into users(user_id, user_account, user_name, user_password, coins, card_splinter)"
                          "values('%1', '%2', '%3', '%4', '%5', '%6')")
            .arg(user_id, user_account, user_name, user_password).arg(coins).arg(card_splinter);
    QSqlQuery query;

    if (!query.exec(str))
    {
        // 执行不成功，返回 false
        return false;
    }

    return true;
}

int User::login(QString account, QString password, QString captcha)   // 用户登录：返回 0成功，1账号不存在，2密码错误，3验证码错误
{
    // 从服务器获取验证码
    if (captcha == "")
    {
        // 如果验证码错误
        return 3;
    }

    // 使用 用户账号 查 users表
    QString str = QString("select * from users where user_account = '%1' ").arg(account);
    QSqlQuery query;
    query.exec(str);

    if (!query.next())
    {
        // 如果查询不成功
        return 1;   // 返回账号不存在
    }
    else if (query.value(3) != password)
    {
        return 2;   // 返回密码错误
    }

    // 如果登录成功
    return 0;
}

void User::update_user_name(QString name)   // 修改用户名
{
    // 检测用户名格式：长度（15），特殊符号

    user_name = name;   // 修改用户名
}

void User::update_user_password(QString password)   // 修改密码
{
    // 查看是否是新用户

    user_password = password;
}

void User::update_anonymity(bool anony)   // 设置是否匿名
{
    anonymity = anony;
}

QString User::return_user_name() // 返回用户名
{
    return user_name;
}

QString User::return_user_ID()   // 返回用户ID
{
    return user_id;
}

bool User::return_anonymity()    // 返回是否匿名
{
    return anonymity;
}


