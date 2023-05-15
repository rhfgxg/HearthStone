#include "ui/battle/battlewindow.h"
#include "ui_battlewindow.h"

// ui界面
#include "ui/battle/victorywindow.h"   // 胜利界面
#include "ui/battle/defeatwindow.h"    // 失败界面
#include "ui/battle/peacewindow.h"     // 平局界面

// UI库
#include <QIcon>    // 为按钮添加图片

battlewindow::battlewindow(QWidget *parent) :   // 构造函数
    QWidget(parent),
    ui(new Ui::battlewindow)
{
    ui->setupUi(this);

    // 定义游戏进程类(空对象)

    // 初始化 牌库按钮数组
    but_card_sets[0] = ui->pushButton_card_set1;
    but_card_sets[1] = ui->pushButton_card_set2;
    // 设置牌库按钮悬停注释
    but_card_sets[0]->setToolTip("剩余卡牌：30");
    but_card_sets[1]->setToolTip("剩余卡牌：30");

    // 初始化并关联己方随从按钮
    connect_minion1();

    // 初始化并关联敌方随从按钮
    connect_minion2();

    // 初始化己方手牌按钮
    connect_hands();

    // 初始化己方手牌图片(3张)    崩
    for (int i=1; i<4; ++i)
    {
        update_hands_image(i);
    }
}

battlewindow::~battlewindow()
{
    delete ui;
}

void battlewindow::on_pushButton_end_clicked()  // 切换回合按钮
{
    if (true != course.up_rounds()) // 如果切换失败
    {
        outcome = peace;    // 设置对战结果：平局
        this->close();  // 关闭对战界面

        // 打开平局界面
        peaceWindow * peaceWin = new peaceWindow;
        peaceWin->show();
    }
    // 切换成功，什么也不做
}

/****************************************** 槽函数 ************************************/
// 多对象槽函数
// 己方随从按钮槽：单击选择，双击取消选择
void battlewindow::connect_minion1()    // 己方随从关联
{
    // 初始化按钮数组
    but_minon1[0] = ui->pushButton_minion11;
    but_minon1[1] = ui->pushButton_minion12;
    but_minon1[2] = ui->pushButton_minion13;
    but_minon1[3] = ui->pushButton_minion14;
    but_minon1[4] = ui->pushButton_minion15;
    but_minon1[5] = ui->pushButton_minion16;
    but_minon1[6] = ui->pushButton_minion17;

    // 点击按钮，开始计时
    connect(but_minon1[0], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked_begin()));
    connect(but_minon1[1], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked_begin()));
    connect(but_minon1[2], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked_begin()));
    connect(but_minon1[3], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked_begin()));
    connect(but_minon1[4], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked_begin()));
    connect(but_minon1[5], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked_begin()));
    connect(but_minon1[6], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked_begin()));

    // 根据点击次数执行操作
    connect(&minion1_cTime[0], SIGNAL(timeout()), this, SLOT(Button_minion11_clicked()));
    connect(&minion1_cTime[1], SIGNAL(timeout()), this, SLOT(Button_minion12_clicked()));
    connect(&minion1_cTime[2], SIGNAL(timeout()), this, SLOT(Button_minion13_clicked()));
    connect(&minion1_cTime[3], SIGNAL(timeout()), this, SLOT(Button_minion14_clicked()));
    connect(&minion1_cTime[4], SIGNAL(timeout()), this, SLOT(Button_minion15_clicked()));
    connect(&minion1_cTime[5], SIGNAL(timeout()), this, SLOT(Button_minion16_clicked()));
    connect(&minion1_cTime[6], SIGNAL(timeout()), this, SLOT(Button_minion17_clicked()));
}

void battlewindow::but_minion1_clicked_begin()     // 己方随从开始计时
{
    QString btnName = QObject::sender()->objectName();
    int index = (btnName.mid(btnName.size()-1,1)).toInt();
    switch(index)
    {
    case 1:
    {
        minion1_clicked_time[0]++;
        minion1_cTime[0].start(200);
        break;
    }
    case 2:
    {
        minion1_clicked_time[1]++;
        minion1_cTime[1].start(200);
        break;
    }
    case 3:
    {
        minion1_clicked_time[2]++;
        minion1_cTime[2].start(200);
        break;
    }
    case 4:
    {
        minion1_clicked_time[3]++;
        minion1_cTime[3].start(200);
        break;
    }
    case 5:
    {
        minion1_clicked_time[4]++;
        minion1_cTime[4].start(200);
        break;
    }
    case 6:
    {
        minion1_clicked_time[5]++;
        minion1_cTime[5].start(200);
        break;
    }
    case 7:
    {
        minion1_clicked_time[6]++;
        minion1_cTime[6].start(200);
    }
    }
}

void battlewindow::Button_minion11_clicked()     // 己方随从1
{
    minion1_cTime[0].stop();
    if(1 == minion1_clicked_time[0]){
        // 单击选中
        // 显示详情
    }
    else if(2 <= minion1_clicked_time[0])
    {
        // 双击取消

    }
    minion1_clicked_time[0]=0;
}

void battlewindow::Button_minion12_clicked()     // 己方随从2
{
    minion1_cTime[1].stop();
    if(1 == minion1_clicked_time[1]){
        // 单击选中
        // 显示详情
    }
    else if(2 <= minion1_clicked_time[1])
    {
        // 双击取消

    }
    minion1_clicked_time[1]=0;
}

void battlewindow::Button_minion13_clicked()     // 己方随从3
{
    minion1_cTime[2].stop();
    if(1 == minion1_clicked_time[2]){
        // 单击选中
        // 显示详情
    }
    else if(2 <= minion1_clicked_time[2])
    {
        // 双击取消

    }
    minion1_clicked_time[2]=0;
}

void battlewindow::Button_minion14_clicked()     // 己方随从4
{
    minion1_cTime[3].stop();
    if(1 == minion1_clicked_time[3]){
        // 单击选中
        // 显示详情
    }
    else if(2 <= minion1_clicked_time[3])
    {
        // 双击取消

    }
    minion1_clicked_time[3]=0;
}

void battlewindow::Button_minion15_clicked()     // 己方随从5
{
    minion1_cTime[4].stop();
    if(1 == minion1_clicked_time[4]){
        // 单击选中
        // 显示详情
    }
    else if(2 <= minion1_clicked_time[4])
    {
        // 双击取消

    }
    minion1_clicked_time[4]=0;
}

void battlewindow::Button_minion16_clicked()     // 己方随从6
{
    minion1_cTime[5].stop();
    if(1 == minion1_clicked_time[5]){
        // 单击选中
        // 显示详情
    }
    else if(2 <= minion1_clicked_time[5])
    {
        // 双击取消

    }
    minion1_clicked_time[5]=0;
}

void battlewindow::Button_minion17_clicked()     // 己方随从7
{
    minion1_cTime[6].stop();
    if(1 == minion1_clicked_time[6]){
        // 单击选中
        // 显示详情
    }
    else if(2 <= minion1_clicked_time[6])
    {
        // 双击取消

    }
    minion1_clicked_time[6]=0;
}

// 敌方随从按钮槽
// 点击选择目标，悬停显示详情
void battlewindow::connect_minion2()    // 敌方随从关联
{
    // 初始化数组
    but_minon2[0] = ui->pushButton_minion21;
    but_minon2[1] = ui->pushButton_minion22;
    but_minon2[2] = ui->pushButton_minion23;
    but_minon2[3] = ui->pushButton_minion24;
    but_minon2[4] = ui->pushButton_minion25;
    but_minon2[5] = ui->pushButton_minion26;
    but_minon2[6] = ui->pushButton_minion27;

    // 点击按钮，选择
    for(int i=0; i<7; ++i)
    {
        connect(but_minon2[i], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));

    }
//    connect(but_minon2[0], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));
//    connect(but_minon2[1], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));
//    connect(but_minon2[2], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));
//    connect(but_minon2[3], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));
//    connect(but_minon2[4], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));
//    connect(but_minon2[5], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));
//    connect(but_minon2[6], SIGNAL(clicked(bool)), this, SLOT(but_minion2_clicked()));
}

void battlewindow::but_minion2_clicked()     // 敌方随从
{

}

// 手牌按钮槽
// 单击查看，双击打出
void battlewindow::connect_hands()  // 手牌按钮关联
{
    // 初始化手牌按钮数组
    but_hands[0] = ui->pushButton_hands1;
    but_hands[1] = ui->pushButton_hands2;
    but_hands[2] = ui->pushButton_hands3;
    but_hands[3] = ui->pushButton_hands4;
    but_hands[4] = ui->pushButton_hands5;
    but_hands[5] = ui->pushButton_hands6;
    but_hands[6] = ui->pushButton_hands7;
    but_hands[7] = ui->pushButton_hands8;
    but_hands[8] = ui->pushButton_hands9;
    but_hands[9] = ui->pushButton_hands10;

    // 点击按钮，开始计时
    for(int i=0; i<10; ++i)
    {
        connect(but_hands[i], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
    }
//    connect(but_hands[0], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[1], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[2], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[3], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[4], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[5], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[6], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[7], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[8], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));
//    connect(but_hands[9], SIGNAL(clicked(bool)), this, SLOT(but_hands_clicked_begin()));

    // 根据点击次数执行操作
    connect(&hands_cTime[0], SIGNAL(timeout()), this, SLOT(Button_hands1_clicked()));
    connect(&hands_cTime[1], SIGNAL(timeout()), this, SLOT(Button_hands2_clicked()));
    connect(&hands_cTime[2], SIGNAL(timeout()), this, SLOT(Button_hands3_clicked()));
    connect(&hands_cTime[3], SIGNAL(timeout()), this, SLOT(Button_hands4_clicked()));
    connect(&hands_cTime[4], SIGNAL(timeout()), this, SLOT(Button_hands5_clicked()));
    connect(&hands_cTime[5], SIGNAL(timeout()), this, SLOT(Button_hands6_clicked()));
    connect(&hands_cTime[6], SIGNAL(timeout()), this, SLOT(Button_hands7_clicked()));
    connect(&hands_cTime[7], SIGNAL(timeout()), this, SLOT(Button_hands8_clicked()));
    connect(&hands_cTime[8], SIGNAL(timeout()), this, SLOT(Button_hands9_clicked()));
    connect(&hands_cTime[9], SIGNAL(timeout()), this, SLOT(Button_hands10_clicked()));
}

void battlewindow::but_hands_clicked_begin()     // 手牌点击开始计时
{
    QString btnName = QObject::sender()->objectName();
    int index = (btnName.mid(btnName.size()-1,1)).toInt();
    switch(index)
    {
    case 1:
    {
        hands_clicked_time[0]++;
        hands_cTime[0].start(200);
        break;
    }
    case 2:
    {
        hands_clicked_time[1]++;
        hands_cTime[1].start(200);
        break;
    }
    case 3:
    {
        hands_clicked_time[2]++;
        hands_cTime[2].start(200);
        break;
    }
    case 4:
    {
        hands_clicked_time[3]++;
        hands_cTime[3].start(200);
        break;
    }
    case 5:
    {
        hands_clicked_time[4]++;
        hands_cTime[4].start(200);
        break;
    }
    case 6:
    {
        hands_clicked_time[5]++;
        hands_cTime[5].start(200);
        break;
    }
    case 7:
    {
        hands_clicked_time[6]++;
        hands_cTime[6].start(200);
        break;
    }
    case 8:
    {
        hands_clicked_time[7]++;
        hands_cTime[7].start(200);
        break;
    }
    case 9:
    {
        hands_clicked_time[8]++;
        hands_cTime[8].start(200);
        break;
    }
    case 0:
    {
        hands_clicked_time[9]++;
        hands_cTime[9].start(200);
    }
    }
}

void battlewindow::Button_hands1_clicked()     // 手牌1
{
    hands_cTime[0].stop();
    if(1 == hands_clicked_time[0]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[0])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands2_clicked()     // 手牌2
{
    hands_cTime[1].stop();
    if(1 == hands_clicked_time[1]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[1])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands3_clicked()     // 手牌3
{
    hands_cTime[2].stop();
    if(1 == hands_clicked_time[2]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[2])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands4_clicked()     // 手牌4
{
    hands_cTime[3].stop();
    if(1 == hands_clicked_time[3]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[3])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands5_clicked()     // 手牌5
{
    hands_cTime[4].stop();
    if(1 == hands_clicked_time[4]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[4])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands6_clicked()     // 手牌6
{
    hands_cTime[5].stop();
    if(1 == hands_clicked_time[5]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[5])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands7_clicked()     // 手牌7
{
    hands_cTime[6].stop();
    if(1 == hands_clicked_time[6]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[6])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands8_clicked()     // 手牌8
{
    hands_cTime[7].stop();
    if(1 == hands_clicked_time[7]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[7])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands9_clicked()     // 手牌9
{
    hands_cTime[8].stop();
    if(1 == hands_clicked_time[8]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[8])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

void battlewindow::Button_hands10_clicked()     // 手牌10
{
    hands_cTime[9].stop();
    if(1 == hands_clicked_time[9]){
        // 单击响应
        // 显示详情
    }
    else if(2 <= hands_clicked_time[9])
    {
        // 双击出牌

    }
    hands_clicked_time[0]=0;    // 重置计数器
}

/*************************************** 工具函数 *************************************************/
void battlewindow::update_hands_image(int page)    // 刷新手牌图片：打出和加入时刷新
{
    page -= 1;     // 修正UI位置 与 数组下标偏差

    // 根据 card_id使用对应图片初始化
    QIcon myicon; //新建QIcon对象

    // (course.return_hands1().return_card(page)) course->hands->card，得到卡牌
    // 使用卡牌类的函数得到卡牌ID
    // 转换成 string 以拼接字符串
    std::string url = ":/image/initial/src/image/" + (course.return_hands1().return_card(page)).return_id().toStdString() + ".png";   // 拼接地址
    // string.c_str()将 string转换成 c字符串
    myicon.addFile(tr(url.c_str()));    // 让QIcon对象指向想要的图标

    but_hands[page]->setIcon(myicon);  // 给按钮添加图标
    but_hands[page]->setIconSize(QSize(51,81));  // 设置图片大小
}

