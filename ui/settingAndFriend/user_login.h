#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include "user/user.h"

#include <QWidget>
#include <QHBoxLayout>  // 水平布局
#include <QVBoxLayout>  // 垂直布局
#include <QGridLayout>  // 网格布局
#include <QSpacerItem>  // 弹簧
#include <QLabel>   // 标签
#include <QLineEdit>    // 单行输入框
#include <QPushButton>

namespace Ui {
class User_login;
}

class User_login : public QWidget
{
    Q_OBJECT

public:
    explicit User_login(QWidget *parent = nullptr);
    ~User_login();

private:
    void add_ui();  // 添加 UI

    /*
        public slots：在这个区内声明的槽意味着任何对象都可将信号与之相连接。公开槽。可以创建彼此互不了解的对象，将它们的信号与槽进行连接以便信息能够正确的传递。

        protected slots：在这个区内声明的槽意味着当前类及其子类可以将信号与之相连接。保护槽。适用于那些槽，它们是类实现的一部分，但是其界面接口却面向外部。

        private slots：在这个区内声明的槽意味着只有类自己可以将信号与之相连接。私有槽，默认类型。这适用于联系非常紧密的类。
    */

private slots:
    void pushButton_login_clicked();   // 登录
    void pushButton_enroll_clicked();   // 注册
    void pushButton_cancel_clicked();   // 取消

private:
    QLabel *label_account;   // 账号
    QLabel *label_password;  // 密码
    QLabel *label_captcha;   // 验证码
    QLineEdit *lineEdit_accont;      // 账号输入
    QLineEdit *lineEdit_password;    //密码输入
    QLineEdit *lineEdit_captcha;     // 验证码输入
    QPushButton *pushButton_new_captcha; // 获取验证码

    QPushButton *pushButton_login;   // 登录
    QPushButton *pushButton_enroll;  // 注册
    QPushButton *pushButton_cancel;  // 取消

    // 水平布局
    QHBoxLayout *hBoxLayout_accout; // 账号
    QHBoxLayout *hBoxLayout_password;   // 密码
    QHBoxLayout *hBoxLayout_captcha;    // 验证码
    QHBoxLayout *hBoxLayout_ptn;    // 登录和取消按钮
    QSpacerItem *spacerItem_r;  // 取消和注册之间
    QSpacerItem *spacerItem_l;  // 注册和登录之间
    QSpacerItem *spacerItem_bottom; // 输入区和按钮区之间

    QVBoxLayout *vBoxLayout_account;    // 全局垂直布局

    Ui::User_login *ui;

    User user;  // 用户对象
};

#endif // USER_LOGIN_H
