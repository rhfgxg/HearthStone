#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QTime> // 延时器

#include <QWidget>

namespace Ui {
class mainWindow;
}

// 游戏主界面
class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void on_pushButton_battle_clicked();    // 对战模式

    void on_pushButton_venture_clicked();   // 冒险模式

    void on_pushButton_athletic_clicked();  // 竞技模式按钮

    void on_pushButton_Brawl_clicked();     // 乱斗模式按钮

    void on_pushButton_collection_clicked();    // 收藏按钮

    void on_pushButton_playback_clicked();      // 回放按钮

    void on_pushButton_friend_clicked(bool checked);    // 好友按钮

    void on_pushButton_setting_clicked();   // 设置按钮

private:
    void sleep(unsigned int msec);  // 延时器

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
