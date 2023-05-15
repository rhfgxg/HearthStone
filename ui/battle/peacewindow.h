#ifndef PEACEWINDOW_H
#define PEACEWINDOW_H

#include <QWidget>

namespace Ui {
class peaceWindow;
}

// 平局界面
class peaceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit peaceWindow(QWidget *parent = nullptr);
    ~peaceWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::peaceWindow *ui;
};

#endif // PEACEWINDOW_H
