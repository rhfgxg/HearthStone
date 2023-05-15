#include "ui/widget.h"
#include "ui_widget.h"

#include "mainwindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()    // 点击继续
{
    this->close();  // 关闭当前窗口

    mainWindow * mainWin = new mainWindow;  // 打开游戏主界面
    mainWin->show();
}

