#ifndef VICTORYWINDOW_H
#define VICTORYWINDOW_H

#include <QWidget>

namespace Ui {
class victoryWindow;
}

// 胜利界面
class victoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit victoryWindow(QWidget *parent = nullptr);
    ~victoryWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::victoryWindow *ui;
};

#endif // VICTORYWINDOW_H
