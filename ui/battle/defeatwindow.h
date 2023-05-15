#ifndef DEFEATWINDOW_H
#define DEFEATWINDOW_H

#include <QWidget>

namespace Ui {
class defeatWindow;
}

// 失败界面
class defeatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit defeatWindow(QWidget *parent = nullptr);
    ~defeatWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::defeatWindow *ui;
};

#endif // DEFEATWINDOW_H
