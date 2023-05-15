#include "ui/settingAndFriend/setwindow.h"
#include "ui_setwindow.h"

setWindow::setWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setWindow)
{
    ui->setupUi(this);
}

setWindow::~setWindow()
{
    delete ui;
}
