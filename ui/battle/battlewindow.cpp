#include "ui/battle/battlewindow.h"
#include "ui_battlewindow.h"

// ui界面
#include "ui/battle/victorywindow.h"   // 胜利界面
#include "ui/battle/defeatwindow.h"    // 失败界面
#include "ui/battle/peacewindow.h"     // 平局界面

// UI库
#include <QIcon>    // 为按钮添加图片
#include <QScreen>  // 根据屏幕比例设置窗口大小

battlewindow::battlewindow(QWidget *parent) :   // 构造函数
    QWidget(parent),
    ui(new Ui::battlewindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶
    resize(QGuiApplication::primaryScreen()->availableSize() * 1);    // 根据屏幕比例设置窗口大小，将窗口大小设置为屏幕大小的 1/1=1。

    // 定义游戏进程类(空对象)

    // 初始化按钮
    but_card_sets[0] = ui->pushButton_card_set1;    // 初始化 牌库按钮数组
    but_card_sets[1] = ui->pushButton_card_set2;    // 初始化 牌库按钮数组
    connect_minion1();  // 初始化并关联己方随从按钮
    connect_minion2();  // 初始化并关联敌方随从按钮
    connect_hands();    // 初始化己方手牌按钮

    // 初始化图片
    for (int i=1; i<5; ++i) // 初始化己方手牌图片(4张)
    {
        update_hands1_image();  // 刷新图片
    }
    for (int i=1; i<6; ++i) // 初始化敌方手牌图片(5张) 4张牌1张水晶
    {
        course.return_hands2().add(course.return_card_set2().draw_out());// 抽牌
        update_hands2_image();
    }
    update_hero();  // 初始化双方英雄图片

    // 初始化文本相关
    but_card_sets[0]->setToolTip("剩余卡牌：30");    // 己方牌库按钮悬停注释
    but_card_sets[1]->setToolTip("剩余卡牌：30");    // 对方牌库按钮悬停注释
    // 初始化水晶文本
    ui->lanel_mana->setText("水晶：" + QString::number(course.return_mana1()) + "/" + QString::number(course.return_Max_mana1()));
}

battlewindow::~battlewindow()
{
    delete ui;
}

/****************************************** 槽函数 ************************************/
void battlewindow::on_pushButton_end_clicked()  // 切换回合按钮
{
    if (!course.up_rounds()) // 如果切换失败：平局
    {
        outcome = peace;    // 设置对战结果：平局

        this->close();  // 关闭对战界面
        // 打开平局界面
        peaceWindow * peaceWin = new peaceWindow;
        peaceWin->show();
    }
    // 切换成功
    if(course.return_user())    // user1
    {
        update_hands1_image();  // 刷新 user1手牌图片
        // 刷新 user1水晶文本
        ui->lanel_mana->setText("水晶：" + QString::number(course.return_mana1()) + "/" + QString::number(course.return_Max_mana1()));
        ui->pushButton_end->setText("回合结束");    // 修改回合结束按钮文本

    }
    else
    {
        update_hands2_image();  // 刷新 user1手牌图片

        // 刷新 user2水晶文本
        ui->lanel_mana->setText("水晶：" + QString::number(course.return_mana2()) + "/" + QString::number(course.return_Max_mana2()));
        ui->pushButton_end->setText("对方回合");    // 修改回合结束按钮文本

    }
}

void battlewindow::on_pushButton_setting_clicked()  // 设置按钮
{
    outcome = defeat;   // 设置对战结果：失败
    this->close();  // 关闭对战界面

    // 打开失败界面
    defeatWindow * defeatWin = new defeatWindow;
    defeatWin->show();
}

// 多对象槽函数
// 敌方随从按钮槽
// 点击选择目标
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

void battlewindow::but_minion2_clicked()     // 敌方随从按钮槽
{

}

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

    // 点击按钮
    connect(but_minon1[0], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked()));
    connect(but_minon1[1], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked()));
    connect(but_minon1[2], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked()));
    connect(but_minon1[3], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked()));
    connect(but_minon1[4], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked()));
    connect(but_minon1[5], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked()));
    connect(but_minon1[6], SIGNAL(clicked(bool)), this, SLOT(but_minion1_clicked()));

}

void battlewindow::but_minion1_clicked()     // 己方随从槽函数
{

}

// 手牌按钮槽
// 单击查看，双击打出
void battlewindow::connect_hands()  // 己方手牌按钮关联
{
    // 初始化手牌按钮数组
    but_hands1[0] = ui->pushButton_hands1;
    but_hands1[1] = ui->pushButton_hands2;
    but_hands1[2] = ui->pushButton_hands3;
    but_hands1[3] = ui->pushButton_hands4;
    but_hands1[4] = ui->pushButton_hands5;
    but_hands1[5] = ui->pushButton_hands6;
    but_hands1[6] = ui->pushButton_hands7;
    but_hands1[7] = ui->pushButton_hands8;
    but_hands1[8] = ui->pushButton_hands9;
    but_hands1[9] = ui->pushButton_hands10;

    // 关联手牌槽函数
    for(int i=0; i<10; ++i)
    {
        connect(but_hands1[i], SIGNAL(clicked(bool)), this, SLOT(Button_hands_clicked()));
    }
}

void battlewindow::Button_hands_clicked()     // 手牌槽函数：单击打出
{
    QString btnName = QObject::sender()->objectName();
    unsigned index = (btnName.mid(btnName.size()-1,1)).toInt();  // 获取按钮名（手牌下标）

    if(index > course.return_hands1().size_hands() || index == 0)   // 如果点击的手牌位置没有目标手牌
    {
        return; // 结束函数
    }

    Card out_card = course.return_hands1().out(index);  // 在手牌数组中移出对应卡牌，并返回副本

    update_hands1_image();   // 刷新所有手牌中存在的图片
    for (unsigned i=course.return_hands1().size_hands()-1; i<10; ++i) // 删除最后一张手牌的图片
    {
        but_hands1[i]->setIcon(QIcon());
    }

    // 将手牌放入战场
    course.return_venue1().add(out_card);
    // 刷新场上图片
    update_minions1_image();
}
/*************************************** 工具函数 *************************************************/
void battlewindow::update_hero() // 初始化英雄图片
{
    // 根据 card_id使用对应图片初始化
    QIcon myicon; //新建QIcon对象

    std::string url;    // 保存图片地址
    // (course.return_hands1().return_card(page)) course->hands->card，得到卡牌
    // 使用卡牌类的函数得到卡牌ID
    // 转换成 string 以拼接字符串

    std::string name = "HERO_06";
    url = ":/image/initial/src/image/" + name + ".png";   // 拼接地址
    // string.c_str()将 string转换成 c字符串
    myicon.addFile(tr(url.c_str()));    // 让QIcon对象指向想要的图标

    ui->pushButton_hero1->setIcon(myicon);  // 给按钮添加图标
    ui->pushButton_hero1->setIconSize(QSize(51,91));  // 设置图片大小

    ui->pushButton_hero2->setIcon(myicon);  // 给按钮添加图标
    ui->pushButton_hero2->setIconSize(QSize(51,91));  // 设置图片大小
}

void battlewindow::update_hands1_image()    // 刷新己方手牌图片：打出和加入时刷新
{
    // 根据 card_id使用对应图片初始化
    QIcon myicon; //新建QIcon对象
    QString url;    // 保存图片地址
    QString name;   // 保存图片名

    // 使用卡牌类的函数得到卡牌ID
    // 转换成 string 以拼接字符串
    for(unsigned i=0; i<course.return_hands1().size_hands(); ++i)
    {
        name = (course.return_hands1().return_card(i)).return_id() + ".png";   // 获取图片名
        url = ":/image/initial/src/image/" + name;   // 拼接地址
        // string.c_str()将 string转换成 c字符串
        myicon.addFile(url);    // 让QIcon对象指向想要的图标

        but_hands1[i]->setIcon(myicon);  // 给按钮添加图标
        but_hands1[i]->setIconSize(QSize(51,81));  // 设置图片大小
    }

    // 刷新牌库和手牌悬浮信息
    but_card_sets[0]->setToolTip("牌库剩余卡牌：" + QString::number(course.return_card_set1().size_card_set()));
}

void battlewindow::update_hands2_image()    // 刷新敌方手牌图片 缺少卡背图片
{
//    // 根据 card_id使用对应图片初始化
//    QIcon myicon; //新建QIcon对象

//    std::string url;    // 保存图片地址
//    std::string name;
//    // (course.return_hands1().return_card(page)) course->hands->card，得到卡牌
//    // 使用卡牌类的函数得到卡牌ID
//    // 转换成 string 以拼接字符串
//    for(unsigned i=0; i<course.return_hands1().return_counter_hands(); ++i)
//    {
//        name = ".png";   // 卡背图案名
//        url = ":/image/initial/src/image/" + name;   // 拼接地址
//        // string.c_str()将 string转换成 c字符串
//        myicon.addFile(tr(url.c_str()));    // 让QIcon对象指向想要的图标

//        but_hands2[i]->setIcon(myicon);  // 给按钮添加图标
//        but_hands2[i]->setIconSize(QSize(51,81));  // 设置图片大小
//    }

//    // 刷新敌方牌库剩余卡牌文本（悬浮）
//    but_card_sets[1]->setToolTip("剩余卡牌：" + QString::number(course.return_card_set2().return_counter_card_set()));
}

void battlewindow::update_minions1_image()  // 刷新己方随从图片
{
    // 根据 card_id使用对应图片初始化
    QIcon myicon; //新建QIcon对象

    QString url;    // 保存图片地址
    QString name;
    // (course.return_hands1().return_card(page)) course->hands->card，得到卡牌
    // 使用卡牌类的函数得到卡牌ID
    // 转换成 string 以拼接字符串
    for(unsigned i=0; i<course.return_venue1().size_venue(); ++i)
    {
        name = (course.return_venue1().return_minion(i)).return_id() + ".png";   // 获取图片名
        url = ":/image/cards/classic/400px-Art_" + name;   // 拼接地址
        // string.c_str()将 string转换成 c字符串
        myicon.addFile(url);    // 让QIcon对象指向想要的图标

        but_minon1[i]->setIcon(myicon);  // 给按钮添加图标
        but_minon1[i]->setIconSize(QSize(51,81));  // 设置图片大小
    }
}

void battlewindow::update_minions2_image()  // 刷新敌方随从图片
{

}
