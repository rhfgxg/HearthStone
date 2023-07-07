#ifndef COLLECTIONWINDOW_H
#define COLLECTIONWINDOW_H

// 自定义文件
#include "cards/cards.h"     // 组建卡组界面
#include "card/card.h"

#include <vector>       // 容器
#include <QTimer>       // 计时器类
// #include <QTime>     // 时间类

#include <QWidget>
#include <QPushButton>  // 按钮

namespace Ui {
class collectionWindow;
}

// 组建卡组界面

class collectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit collectionWindow(QWidget *parent = nullptr);
    ~collectionWindow();

private:
    // 工具函数
    void update_image();    // 初始化八张图片
    void update_text();     // 刷新所有卡组按钮的文本

    void connect_cards();   // 卡组按钮关联
    void connect_card();    // 卡牌按钮关联

private slots:
    void on_Button_last_clicked();  // 上一页按钮
    void on_Button_next_clicked();  // 下一页按钮

    void on_Button_save_cards_clicked();    // 保存卡组按钮

    void on_pushButton_back_clicked();    // 返回按钮

    void Button_cards_clicked();    // 卡组按钮槽

    void but_card_clicked();     // 点击开始计时
    void Button_card1_clicked();     // 卡牌1按钮响应
    void Button_card2_clicked();     // 卡牌2按钮响应
    void Button_card3_clicked();     // 卡牌3按钮响应
    void Button_card4_clicked();     // 卡牌4按钮响应
    void Button_card5_clicked();     // 卡牌5按钮响应
    void Button_card6_clicked();     // 卡牌6按钮响应
    void Button_card7_clicked();     // 卡牌7按钮响应
    void Button_card8_clicked();     // 卡牌8按钮响应

private:
    QPushButton * butCard[8];   // 保存八个卡牌按钮
    QPushButton * butCards[30]; // 保存卡组内的按

    Ui::collectionWindow *ui;

    int page;   // 页面计数器
    int m_clicked_time[8];     // 点击次数
    QTimer m_cTime[8];      // 计时器

    std::vector<Card> card;    //用来存储 所有card

    Cards cards;     // 卡组对象
    std::vector<QString> text;   // 保存 30个按钮的文本
};

#endif // COLLECTIONWINDOW_H
