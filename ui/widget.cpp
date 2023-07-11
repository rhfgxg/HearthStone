#include "ui/widget.h"
#include "ui_widget.h"

//#include "ui/settingAndFriend/user_login.h"
#include "ui/mainwindow.h"

#include"QMouseEvent"   // 鼠标
#include <QScreen>  // 根据屏幕比例设置窗口大小

// 打开界面
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶
    resize(QGuiApplication::primaryScreen()->availableSize() * 1);    // 根据屏幕比例设置窗口大小

    // 背景图片
    QPalette pal =this->palette();
    pal.setBrush(QPalette::Window, QBrush(QPixmap(":/image/main/LoadingScreen.png")));
    setPalette(pal);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::mousePressEvent(QMouseEvent *e)    // 鼠标点击事件
{
    if(e->button()==Qt::LeftButton)
    {
        this->close();  // 关闭当前界面
        // 左键按下
        // 打开登录界面，如果登录成功，打开主界面

//        User_login *w = new User_login;
        mainWindow *w = new mainWindow;
        w->show();

    }

}

