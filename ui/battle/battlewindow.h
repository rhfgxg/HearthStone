#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include "course/course.h"   // 回合类

#include <QTimer>       // 计时器类

#include <QWidget>
#include <QPushButton>

namespace Ui {
class battlewindow;
}

// 对战界面
class battlewindow : public QWidget
{
    Q_OBJECT

public:
    explicit battlewindow(QWidget *parent = nullptr);
    ~battlewindow();

private:
    void connect_minion1();     // 己方随从关联
    void connect_minion2();     // 敌方随从关联
    void connect_hands();       // 手牌按钮关联

    void update_hero(); // 初始化英雄图片
    void update_hands1_image();  // 刷新己方手牌图片
    void update_hands2_image();  // 刷新敌方手牌图片
    void update_minions1_image(); // 刷新己方随从图片
    void update_minions2_image();// 刷新敌方随从图片

private slots:
    void on_pushButton_end_clicked();   // 切换回合

    // 多对象槽函数
    // 己方随从按钮槽
    void but_minion1_clicked();     // 己方随从：如果没有对应随从就放入随从，如果有随从就是选择随从
    // 敌方随从按钮槽
    void but_minion2_clicked();     // 敌方随从：点击选择目标，悬停显示详情
    // 手牌按钮槽
    void Button_hands_clicked();     // 手牌点击开始计时

    void on_pushButton_setting_clicked();   // 设置按钮

private:
    QPushButton* but_card_sets[2];     // 牌库按钮数组
    QPushButton* but_minon1[7];         // 己方场上随从
    QPushButton* but_minon2[7];         // 敌方场上随从
    QPushButton* but_hands1[10];        // 己方手牌按钮
    QPushButton* but_hands2[10];        // 己方手牌按钮

    Ui::battlewindow *ui;

    Course course;    // 创建游戏进程

    // 对战结果枚举：victory胜利，defeat失败，peace平局
    enum outcome {victory, defeat, peace} outcome;   // 对战结果成员：outcome

    int minion1_clicked_time[7];     // 己方随从按钮点击次数
    QTimer minion1_cTime[7];      // 己方随从按钮计时器
};

#endif // BATTLEWINDOW_H
