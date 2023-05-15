#include "ui/settingAndFriend/friendwindow.h"
#include "ui_friendwindow.h"

friendWindow::friendWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::friendWindow)
{
    ui->setupUi(this);
}

friendWindow::~friendWindow()
{
    delete ui;
}
