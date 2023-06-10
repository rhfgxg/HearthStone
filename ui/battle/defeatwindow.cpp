#include "ui/battle/defeatwindow.h"
#include "ui_defeatwindow.h"

#include "ui/mainwindow.h"  // 主界面

#include <QScreen>  // 根据屏幕比例设置窗口大小

// 失败界面
defeatWindow::defeatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::defeatWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶
    resize(QGuiApplication::primaryScreen()->availableSize() * 1);    // 根据屏幕比例设置窗口大小，将窗口大小设置为屏幕大小的 1/1=1。

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

