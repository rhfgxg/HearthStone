#include "ui/battle/peacewindow.h"
#include "ui_peacewindow.h"

#include "ui/mainwindow.h"  // 主界面

// 平局界面
peaceWindow::peaceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::peaceWindow)
{
    ui->setupUi(this);
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

