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

    void update_hands_image(int page);    // 刷新手牌图片：打出和加入时刷新，传入在手牌中的位置

private slots:
    void on_pushButton_end_clicked();   // 切换回合

    // 多对象槽函数
    // 己方随从按钮槽
    void but_minion1_clicked_begin();     // 己方随从开始计时
    // 槽函数
    void Button_minion11_clicked();     // 手牌1
    void Button_minion12_clicked();     // 手牌2
    void Button_minion13_clicked();     // 手牌3
    void Button_minion14_clicked();     // 手牌4
    void Button_minion15_clicked();     // 手牌5
    void Button_minion16_clicked();     // 手牌6
    void Button_minion17_clicked();     // 手牌7

    // 敌方随从按钮槽
    void but_minion2_clicked();     // 敌方随从：点击选择目标，悬停显示详情

    // 手牌按钮槽
    void but_hands_clicked_begin();     // 手牌点击开始计时

    void Button_hands1_clicked();     // 手牌1
    void Button_hands2_clicked();     // 手牌2
    void Button_hands3_clicked();     // 手牌3
    void Button_hands4_clicked();     // 手牌4
    void Button_hands5_clicked();     // 手牌5
    void Button_hands6_clicked();     // 手牌6
    void Button_hands7_clicked();     // 手牌7
    void Button_hands8_clicked();     // 手牌8
    void Button_hands9_clicked();     // 手牌9
    void Button_hands10_clicked();     // 手牌10

private:
    Ui::battlewindow *ui;
    QPushButton* but_card_sets[2];     // 牌库按钮数组
    QPushButton* but_minon1[7];         // 己方场上随从
    QPushButton* but_minon2[7];         // 敌方场上随从
    QPushButton* but_hands[10];        // 手牌按钮

    Course course;    // 进程类对象

    // 对战结果枚举：victory胜利，defeat失败，peace平局
    enum outcome {victory, defeat, peace} outcome;   // 对战结果成员：outcome

    int minion1_clicked_time[7];     // 己方随从按钮点击次数
    QTimer minion1_cTime[7];      // 己方随从按钮计时器

    int hands_clicked_time[10];     // 手牌按钮点击次数
    QTimer hands_cTime[10];      // 手牌按钮计时器
};

#endif // BATTLEWINDOW_H
