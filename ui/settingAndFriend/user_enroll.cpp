#include "user_enroll.h"
#include "ui_user_enroll.h"

#include "ui/settingAndFriend/user_login.h"

#include <QCryptographicHash>   // 哈希加密

#include <QSpacerItem>  // 弹簧

// 用户注册
User_enroll::User_enroll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_enroll)
{
    ui->setupUi(this);
    add_ui();

    connect(pushButton_enroll, SIGNAL(clicked()), this, SLOT(pushButton_enroll_clicked())); // 注册
    connect(pushButton_cancel, SIGNAL(clicked()), this, SLOT(pushButton_cancel_clicked())); // 取消
}

User_enroll::~User_enroll()
{
    delete ui;
}

void User_enroll::pushButton_enroll_clicked()   // 注册
{
    // 获取账号密码
    QString account = lineEdit_accont->text();
    QString name = lineEdit_name->text();
    QString password = lineEdit_password->text();

    // 检查错误，弹出提示

    // 对密码进行加密
    QByteArray byteArray = password.toLatin1(); // 将 QString转换成 QByteArray
    QByteArray hash = QCryptographicHash::hash(byteArray, QCryptographicHash::Md5);    // 进行加密后返回一个 QByteArray 对象
    QString password_md5 = hash.toHex();    // 转换成十六进制数，并用 QString保存

    if (user.enroll(account, name, password_md5))  // 调用登录函数，根据返回值确定动作
    {
        // 如果没有错误
        this->close();
        User_login *w = new User_login; // 打开登录界面
        w->show();
    }

}

void User_enroll::pushButton_cancel_clicked()   // 取消
{
    this->close();
    User_login *w = new User_login; // 打开登录界面
    w->show();
}

void User_enroll::add_ui()  // 添加UI
{
    vBoxLayout_account = new QVBoxLayout;  // 全局垂直布局

    // 账号
    hBoxLayout_accout = new QHBoxLayout;   // 账号水平布局
    label_account = new QLabel(this);
    label_account->setText("账号");
    lineEdit_accont = new QLineEdit(this);
    lineEdit_accont->setPlaceholderText("请输入账号");
    hBoxLayout_accout->setSpacing(15);  // 布局之间间隔
    hBoxLayout_accout->addWidget(label_account);    // 将控件添加到布局
    hBoxLayout_accout->addWidget(lineEdit_accont);

    // 用户名
    hBoxLayout_name = new QHBoxLayout;
    label_name = new QLabel(this);
    label_name->setText("用户名");
    lineEdit_name = new QLineEdit(this);
    lineEdit_name->setPlaceholderText("请输入用户名");
    hBoxLayout_name->setSpacing(15);
    hBoxLayout_name->addWidget(label_name);
    hBoxLayout_name->addWidget(lineEdit_name);

    // 密码
    hBoxLayout_password = new QHBoxLayout;
    label_password = new QLabel(this);
    label_password->setText("密码");
    lineEdit_password = new QLineEdit(this);
    lineEdit_password->setEchoMode (QLineEdit::Password);   // 隐藏输入密码
    lineEdit_password->setPlaceholderText("请输入密码");
    hBoxLayout_password->setSpacing(15);
    hBoxLayout_password->addWidget(label_password);
    hBoxLayout_password->addWidget(lineEdit_password);

    // 再次输入密码
    hBoxLayout_password_again = new QHBoxLayout;
    label_password_again = new QLabel(this);
    label_password_again->setText("再次输入密码");
    lineEdit_password_again = new QLineEdit(this);
    lineEdit_password_again->setEchoMode (QLineEdit::Password);   // 隐藏输入密码
    lineEdit_password_again->setPlaceholderText("请再次输入密码");
    hBoxLayout_password_again->setSpacing(15);
    hBoxLayout_password_again->addWidget(label_password_again);
    hBoxLayout_password_again->addWidget(lineEdit_password_again);

    // 验证码
    hBoxLayout_captcha = new QHBoxLayout;
    label_captcha = new QLabel(this);
    label_captcha->setText("验证码");
    lineEdit_captcha = new QLineEdit(this);
    lineEdit_captcha->setPlaceholderText("请输入验证码，验证码为邮箱发送");
    pushButton_new_captcha = new QPushButton(this);
    pushButton_new_captcha->setText("获取验证码");
    hBoxLayout_captcha->setSpacing(15);
    hBoxLayout_captcha->addWidget(label_captcha);
    hBoxLayout_captcha->addWidget(lineEdit_captcha);
    hBoxLayout_captcha->addWidget(pushButton_new_captcha);

    // 注册，取消按钮
    hBoxLayout_ptn = new QHBoxLayout;  // 按钮区布局
    pushButton_cancel = new QPushButton;
    pushButton_cancel->setText("取消");
    pushButton_enroll = new QPushButton;
    pushButton_enroll->setText("注册");
    QSpacerItem *spacerItem_ptn = new QSpacerItem(30, 10);  // 一个长度为 30的弹簧
    hBoxLayout_ptn->addWidget(pushButton_enroll);
    hBoxLayout_ptn->addItem(spacerItem_ptn);
    hBoxLayout_ptn->addWidget(pushButton_cancel);

    // 全局布局
    vBoxLayout_account->setSpacing(15);
    vBoxLayout_account->addLayout(hBoxLayout_accout);
    vBoxLayout_account->addLayout(hBoxLayout_name);
    vBoxLayout_account->addLayout(hBoxLayout_password);
    vBoxLayout_account->addLayout(hBoxLayout_password_again);
    vBoxLayout_account->addLayout(hBoxLayout_captcha);
    vBoxLayout_account->addLayout(hBoxLayout_ptn);
    QSpacerItem *spacerItem_bottom = new QSpacerItem(30, 10);  // 一个长度为 30的弹簧
    vBoxLayout_account->addItem(spacerItem_bottom);
    this->setLayout(vBoxLayout_account);    // 将布局提升为全局
}
