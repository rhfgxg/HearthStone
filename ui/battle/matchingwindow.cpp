#include "matchingwindow.h"
#include "ui_matchingwindow.h"

#include <QScreen>  // 根据屏幕比例设置窗口大小

// 匹配等待界面
MatchingWindow::MatchingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchingWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶
    resize(QGuiApplication::primaryScreen()->availableSize() * 1);    // 根据屏幕比例设置窗口大小，将窗口大小设置为屏幕大小的 1/1=1。

}

MatchingWindow::~MatchingWindow()
{
    delete ui;
}

void MatchingWindow::on_pushButton_exit_clicked()   // 取消按钮
{

}

