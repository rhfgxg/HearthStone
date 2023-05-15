#include "ui/battle/defeatwindow.h"
#include "ui_defeatwindow.h"

#include "ui/mainwindow.h"  // 主界面

// 失败界面
defeatWindow::defeatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::defeatWindow)
{
    ui->setupUi(this);
}

defeatWindow::~defeatWindow()
{
    delete ui;
}

void defeatWindow::on_pushButton_clicked()  // 返回主界面
{
    this->close();  // 关闭当前界面

    // 唤起主界面
    mainWindow * mainWin = new mainWindow;
    mainWin->show();
}

