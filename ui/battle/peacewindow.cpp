#include "ui/battle/peacewindow.h"
#include "ui_peacewindow.h"

#include "ui/mainwindow.h"  // 主界面

#include <QScreen>  // 根据屏幕比例设置窗口大小

// 平局界面
peaceWindow::peaceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::peaceWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶
    resize(QGuiApplication::primaryScreen()->availableSize() * 1);    // 根据屏幕比例设置窗口大小，将窗口大小设置为屏幕大小的 1/1=1。

}

peaceWindow::~peaceWindow()
{
    delete ui;
}

void peaceWindow::on_pushButton_clicked()  // 返回主界面
{
    this->close();  // 关闭当前界面

    // 唤起主界面
    mainWindow * mainWin = new mainWindow;
    mainWin->show();
}

