#ifndef AUTOWINDOW_H
#define AUTOWINDOW_H

#include <QWidget>

namespace Ui {
class autoWindow;
}

// 丢失界面
class autoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit autoWindow(QWidget *parent = nullptr);
    ~autoWindow();

private:
    Ui::autoWindow *ui;
};

#endif // AUTOWINDOW_H
