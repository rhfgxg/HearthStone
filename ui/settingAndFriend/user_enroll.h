#ifndef USER_ENROLL_H
#define USER_ENROLL_H

#include "user/user.h"

#include <QWidget>
#include <QHBoxLayout>  // 水平布局
#include <QVBoxLayout>  // 垂直布局
#include <QGridLayout>  // 网格布局
#include <QLabel>   // 标签
#include <QLineEdit>    // 单行输入框
#include <QPushButton>

namespace Ui {
class User_enroll;
}

class User_enroll : public QWidget
{
    Q_OBJECT

public:
    explicit User_enroll(QWidget *parent = nullptr);
    ~User_enroll();

private:
    void add_ui();  // 添加 UI

private slots:
    void pushButton_enroll_clicked();   // 注册
    void pushButton_cancel_clicked();   // 取消

private:
    QLabel *label_account;   // 账号
    QLabel *label_name; // 用户名
    QLabel *label_password;  // 密码
    QLabel *label_password_again;   // 再次输入密码
    QLabel *label_captcha;   // 验证码

    QLineEdit *lineEdit_accont;      // 账号输入
    QLineEdit *lineEdit_name;      // 用户名
    QLineEdit *lineEdit_password;    //密码输入
    QLineEdit *lineEdit_password_again;    //密码输入
    QLineEdit *lineEdit_captcha;     // 验证码输入
    QPushButton *pushButton_new_captcha; // 获取验证码

    QPushButton *pushButton_enroll;  // 注册
    QPushButton *pushButton_cancel;  // 取消

    // 水平布局
    QHBoxLayout *hBoxLayout_accout; // 账号
    QHBoxLayout *hBoxLayout_name;   // 用户名
    QHBoxLayout *hBoxLayout_password;   // 密码
    QHBoxLayout *hBoxLayout_password_again;   // 再次输入密码
    QHBoxLayout *hBoxLayout_captcha;    // 验证码
    QHBoxLayout *hBoxLayout_ptn;    // 注册和取消按钮

    QVBoxLayout *vBoxLayout_account;    // 全局垂直布局

    Ui::User_enroll *ui;

    User user;  // 用户对象
};

#endif // USER_ENROLL_H
