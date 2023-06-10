#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User();

    bool enroll(QString account, QString name, QString password);    // 用户注册
    int login(QString account, QString password, QString captcha);   // 用户登录：返回 0成功，1账号不存在，2密码错误，3验证码错误，4验证码超时

    void update_user_name(QString name);   // 修改用户名
    void update_user_password(QString password);   // 修改密码
    void update_anonymity(bool anonymity);   // 设置是否匿名

    QString return_user_ID();   // 返回用户ID
    QString return_user_name(); // 返回用户名
    bool return_anonymity();    // 返回是否匿名

private:
    QString user_account;    // 用户账号
    QString user_id;    // 用户ID
    QString user_name;  // 用户名，允许重名，依靠 UID辨别
    QString user_password;  // 用户密码

    bool anonymity; // 是否匿名

    // 通过接口访问：
    // 货币
    // 收藏
};

#endif // USER_H
