#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QWidget>

namespace Ui {
class setWindow;
}

// 设置界面
class setWindow : public QWidget
{
    Q_OBJECT

public:
    explicit setWindow(QWidget *parent = nullptr);
    ~setWindow();

private:
    Ui::setWindow *ui;
};

#endif // SETWINDOW_H
