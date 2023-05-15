#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H

#include <QWidget>

namespace Ui {
class friendWindow;
}

// 好友界面
class friendWindow : public QWidget
{
    Q_OBJECT

public:
    explicit friendWindow(QWidget *parent = nullptr);
    ~friendWindow();

private:
    Ui::friendWindow *ui;
};

#endif // FRIENDWINDOW_H
