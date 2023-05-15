#include "ui/auto/autowindow.h"
#include "ui_autowindow.h"

autoWindow::autoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::autoWindow)
{
    ui->setupUi(this);
}

autoWindow::~autoWindow()
{
    delete ui;
}
