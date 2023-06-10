#include "user_login.h"
#include "ui_user_login.h"

#include "ui/mainwindow.h"
#include "ui/settingAndFriend/user_enroll.h"    // 用户注册

#include <QCryptographicHash>   // 哈希加密

#include <QSpacerItem>  // 弹簧

User_login::User_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_login)
{
    ui->setupUi(this);

    add_ui();   // 添加 ui

    // 槽函数
    connect(pushButton_login, SIGNAL(clicked()), this, SLOT(pushButton_login_clicked()));   // 登录
    connect(pushButton_enroll, SIGNAL(clicked()), this, SLOT(pushButton_enroll_clicked())); // 注册
    connect(pushButton_cancel, SIGNAL(clicked()), this, SLOT(pushButton_cancel_clicked())); // 取消
}

User_login::~User_login()
{
    delete ui;
}

void User_login::pushButton_login_clicked() // 登录
{
    // 获取账号密码
    QString account = lineEdit_accont->text();
    QString password = lineEdit_password->text();
    QString captcha = lineEdit_captcha->text();

    // 检查语法错误，弹出提示

    // 对密码进行加密
    QByteArray byteArray = password.toLatin1(); // 将 QString转换成 QByteArray
    QByteArray hash = QCryptographicHash::hash(byteArray, QCryptographicHash::Md5);    // 进行加密后返回一个 QByteArray 对象
    QString password_md5 = hash.toHex();    // 转换成十六进制数，并用 QString保存

    switch (user.login(account, password_md5), captcha)  // 调用登录函数，根据返回值确定动作
    {
    case 1:
        // 账号不存在，弹出提示
        break;
    case 2:
        // 密码错误，弹出提示
        break;
    case 3:
        // 验证码错误
        break;
    default:
        // 登录成功，进入主界面
        this->close();
        mainWindow *main = new mainWindow;
        main->show();
    }

}

void User_login::pushButton_enroll_clicked()   // 注册
{
    this->close();
    // 打开注册界面
    User_enroll *w = new User_enroll;
    w->show();
}

void User_login::pushButton_cancel_clicked()    // 取消
{
    this->close();  // 关闭当前页：退出程序
}

void User_login::add_ui()  // 添加 UI
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

    // 登录，注册，取消按钮
    hBoxLayout_ptn = new QHBoxLayout;  // 按钮区布局
    pushButton_cancel = new QPushButton;
    pushButton_cancel->setText("取消");
    pushButton_enroll = new QPushButton;
    pushButton_enroll->setText("注册");
    pushButton_login = new QPushButton;
    pushButton_login->setText("登录");
    QSpacerItem *spacerItem_r = new QSpacerItem(30, 10);  // 一个长度为 30的弹簧
    QSpacerItem *spacerItem_l = new QSpacerItem(30, 10);  // 一个长度为 30的弹簧

    hBoxLayout_ptn->addWidget(pushButton_login);
    hBoxLayout_ptn->addItem(spacerItem_r);    // 添加弹簧到布局
    hBoxLayout_ptn->addWidget(pushButton_enroll);
    hBoxLayout_ptn->addItem(spacerItem_l);
    hBoxLayout_ptn->addWidget(pushButton_cancel);

    // 全局布局
    vBoxLayout_account->setSpacing(15);
    vBoxLayout_account->addLayout(hBoxLayout_accout);
    vBoxLayout_account->addLayout(hBoxLayout_password);
    vBoxLayout_account->addLayout(hBoxLayout_captcha);
    vBoxLayout_account->addLayout(hBoxLayout_ptn);
    QSpacerItem *spacerItem_bottom = new QSpacerItem(30, 10);  // 一个长度为 30的弹簧
    vBoxLayout_account->addItem(spacerItem_bottom);
    this->setLayout(vBoxLayout_account);    // 将布局提升为全局
}
