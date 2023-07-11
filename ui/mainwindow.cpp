#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ui/auto/autowindow.h"     // 未开放界面
#include "ui/battle/battlewindow.h"    // 对战模式界面
#include "ui/collection/collectionwindow.h"     // 收藏界面
#include "ui/settingAndFriend/friendwindow.h"   // 好友界面
#include "server/server.h"  // 服务器

#include <QScreen>  // 根据屏幕比例设置窗口大小

extern Server a;

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶
    resize(QGuiApplication::primaryScreen()->availableSize() * 1);    // 根据屏幕比例设置窗口大小，将窗口大小设置为屏幕大小的 1/1=1

    // 背景图
    QPalette pal =this->palette();
    pal.setBrush(QPalette::Window, QBrush(QPixmap(":/image/main/TheBox_Top.png")));
    setPalette(pal);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButton_battle_clicked()     // 对战模式按钮
{
    this->close();  // 关闭当前窗口

    battlewindow * battleWin = new battlewindow;
    battleWin->show();
}

void mainWindow::on_pushButton_venture_clicked()    // 冒险模式按钮
{
    autoWindow *autoWin = new autoWindow;
    autoWin->show();
}

void mainWindow::on_pushButton_athletic_clicked()   // 竞技模式按钮
{
    autoWindow *autoWin = new autoWindow;
    autoWin->show();
}

void mainWindow::on_pushButton_Brawl_clicked()      // 乱斗模式按钮
{
    autoWindow *autoWin = new autoWindow;
    autoWin->show();

    QString msg = "乱斗#";
    a.on_Send(msg);
}

void mainWindow::on_pushButton_collection_clicked()     // 收藏按钮
{
    this->close();  // 关闭当前窗口

    collectionWindow * collectionWin = new collectionWindow;

    // 延迟1秒

    collectionWin->show();
}

void mainWindow::on_pushButton_playback_clicked()       // 回放按钮
{
    autoWindow *autoWin = new autoWindow;
    autoWin->show();
}

void mainWindow::on_pushButton_friend_clicked(bool checked) // 好友按钮
{
    if(checked)
    {
        friendWindow * friendWin = new friendWindow;
        friendWin->show();
    }
}

void mainWindow::on_pushButton_setting_clicked()    // 设置按钮
{

}

void mainWindow::sleep(unsigned int msec)  // 延时器，参数：需要延迟的时间，单位毫秒
{
    //currnentTime 返回当前时间 用当前时间加上我们要延时的时间msec得到一个新的时刻
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    //用while循环不断比对当前时间与我们设定的时间
    while(QTime::currentTime()<reachTime)
    {
        //如果当前的系统时间尚未达到我们设定的时刻，就让Qt的应用程序类执行默认的处理，
        //以使程序仍处于响应状态。一旦到达了我们设定的时刻，就跳出该循环，继续执行后面的语句。
        QApplication::processEvents(QEventLoop::AllEvents,100);
    }

}
