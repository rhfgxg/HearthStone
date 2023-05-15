#include "ui/battle/victorywindow.h"
#include "ui_victorywindow.h"

#include "ui/mainwindow.h"  // 主界面

// 胜利界面
victoryWindow::victoryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::victoryWindow)
{
    ui->setupUi(this);
}

victoryWindow::~victoryWindow()
{
    delete ui;
}

void victoryWindow::on_pushButton_clicked()  // 返回主界面
{
    this->close();  // 关闭当前界面

    // 唤起主界面
    mainWindow * mainWin = new mainWindow;
    mainWin->show();
}

