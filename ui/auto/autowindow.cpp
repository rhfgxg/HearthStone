#include "ui/auto/autowindow.h"
#include "ui_autowindow.h"

autoWindow::autoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::autoWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶

}

autoWindow::~autoWindow()
{
    delete ui;
}
