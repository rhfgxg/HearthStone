#include "ui/collection/collectionwindow.h"
#include "ui_collectionwindow.h"

#include "ui/mainwindow.h"

// UI库
#include <QIcon>    // 为按钮添加图片
#include <QScreen>  // 根据屏幕比例设置窗口大小

// 功能库
#include <QDebug>   // 终端输出
// 数据库相关
#include <QtSql>
#include <QSqlDatabase> // 数据库头文件
#include <QSqlQuery>    // sql查询
#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
#include <QSqlError>    // 处理 sql 报错信息

collectionWindow::collectionWindow(QWidget *parent) :       // 构造函数
    QWidget(parent),
    ui(new Ui::collectionWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);  // 去掉标题栏,去掉工具栏，窗口置顶
    resize(QGuiApplication::primaryScreen()->availableSize() * 1);    // 根据屏幕比例设置窗口大小，将窗口大小设置为屏幕大小的 1/1=1。



    page = 1;   // 初始化页面计数器
    for(int i=0; i<8; ++i)  // 初始化计时器
    {
        m_clicked_time[i] = 0;
    }

    // 初始化并关联 8个卡牌按钮
    connect_card();

    // 初始化并关联 30个卡组按钮
    connect_cards();

    // 查询 card表，得到所有卡牌的ID
    QSqlQuery query;
    query.exec("select * from card");   //查询所有的 card_id
    while(query.next())
    {
        card.push_back(Card(query.value(0).toString()));      // 使用查询到的id，新建卡牌对象然后保存
    }
    // 初始化八张图片
    update_image();
}

collectionWindow::~collectionWindow()       //析构函数
{
    delete ui;
}

void collectionWindow::on_Button_save_cards_clicked()    // 保存卡组按钮
{
    if(cards.size_cards() < 30)
    {
        // 卡组数量不够，报错，退出函数
        qDebug("卡组数量不足30张");
        return;
    }

    QString cardsName = ui->text_name->toPlainText();   // 获取 ui界面设置的卡组名
    cards.update_name(cardsName);     // 设置卡组名
    cards.update_career("德鲁伊");     // 设置职业

    cards.save();    // 将卡组存入数据库
}

void collectionWindow::on_Button_last_clicked()     // 上一页
{
    if(page == 1)
    {
        // 当前为第一页时，报错，退出函数
        qDebug("已经是第一页");
        return;
    }
    // 否则更新页面图片
    --page; // 页面计数器减一
    update_image(); // 先翻页后更新
}

void collectionWindow::on_Button_next_clicked()     // 下一页
{
    unsigned siz = (page+1)*8;
    if(siz >= card.size())  // 如果下一页超出，报错
    {
        // 当前为最后一页时，报错，退出函数
        qDebug("已经是最后一页");
        return;
    }
    // 否则更新页面图片
    ++page; // 页面计数器加一
    update_image();  // 先翻页后更新
}

// 不同部件，可以链接至同一个槽函数
// 然后在函数中区分信号源，根据信号源区分部件
// 因为下面槽函数 信号源 是都是qTime对象，所以不能用统一的函数
void collectionWindow::connect_card()   // 关联八个card按钮
{
    // 初始化数组：对应八个 card按钮
    butCard[0] = ui->Button_card1;
    butCard[1] = ui->Button_card2;
    butCard[2] = ui->Button_card3;
    butCard[3] = ui->Button_card4;
    butCard[4] = ui->Button_card5;
    butCard[5] = ui->Button_card6;
    butCard[6] = ui->Button_card7;
    butCard[7] = ui->Button_card8;

    // 点击按钮，开始计时
    for(int i=0; i<8; ++i)
    {
        connect(butCard[i], SIGNAL(clicked(bool)), this, SLOT(but_card_clicked()));
    }

    // timeout：信号：定时器超时
    // 根据点击次数执行操作
    connect(&m_cTime[0], SIGNAL(timeout()), this, SLOT(Button_card1_clicked()));
    connect(&m_cTime[1], SIGNAL(timeout()), this, SLOT(Button_card2_clicked()));
    connect(&m_cTime[2], SIGNAL(timeout()), this, SLOT(Button_card3_clicked()));
    connect(&m_cTime[3], SIGNAL(timeout()), this, SLOT(Button_card4_clicked()));
    connect(&m_cTime[4], SIGNAL(timeout()), this, SLOT(Button_card5_clicked()));
    connect(&m_cTime[5], SIGNAL(timeout()), this, SLOT(Button_card6_clicked()));
    connect(&m_cTime[6], SIGNAL(timeout()), this, SLOT(Button_card7_clicked()));
    connect(&m_cTime[7], SIGNAL(timeout()), this, SLOT(Button_card8_clicked()));
}

void collectionWindow::Button_card1_clicked()     // 卡牌按钮槽函数
{
    m_cTime[0].stop();
    if(1==m_clicked_time[0]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[0])
    {
        // 双击响应
        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 添加卡组按钮文本
        text.push_back((card.begin()+((page-1)*8))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[0]=0;
}
void collectionWindow::Button_card2_clicked()     // 卡牌按钮槽函数
{
    m_cTime[1].stop();
    if(1==m_clicked_time[1]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[1])
    {
        // 双击响应

        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8+1)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 更新卡组按钮文本
        text.push_back((card.begin()+((page-1)*8+1))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[1]=0;
}
void collectionWindow::Button_card3_clicked()     // 卡牌按钮槽函数
{
    m_cTime[2].stop();
    if(1==m_clicked_time[2]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[2])
    {
        // 双击响应

        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8+2)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 更新卡组按钮文本
        text.push_back((card.begin()+((page-1)*8+2))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[2]=0;
}
void collectionWindow::Button_card4_clicked()     // 卡牌按钮槽函数
{
    m_cTime[3].stop();
    if(1==m_clicked_time[3]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[3])
    {
        // 双击响应

        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8+3)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 更新卡组按钮文本
        text.push_back((card.begin()+((page-1)*8+3))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[3]=0;
}
void collectionWindow::Button_card5_clicked()     // 卡牌按钮槽函数
{
    m_cTime[4].stop();
    if(1==m_clicked_time[4]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[4])
    {
        // 双击响应

        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8+4)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 更新卡组按钮文本
        text.push_back((card.begin()+((page-1)*8+4))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[4]=0;
}
void collectionWindow::Button_card6_clicked()     // 卡牌按钮槽函数
{
    m_cTime[5].stop();
    if(1==m_clicked_time[5]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[5])
    {
        // 双击响应

        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8+5)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 更新卡组按钮文本
        text.push_back((card.begin()+((page-1)*8+5))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[5]=0;
}
void collectionWindow::Button_card7_clicked()     // 卡牌按钮槽函数
{
    m_cTime[6].stop();
    if(1==m_clicked_time[6]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[6])
    {
        // 双击响应

        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8+6)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 更新卡组按钮文本
        text.push_back((card.begin()+((page-1)*8+6))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[6]=0;
}
void collectionWindow::Button_card8_clicked()     // 卡牌按钮槽函数
{
    m_cTime[7].stop();
    if(1==m_clicked_time[7]){
        // 单击响应
        // 显示详情
    }
    else if(2<=m_clicked_time[7])
    {
        // 双击响应

        // 获取卡牌ID，并加入卡组
        cards.get(*(card.begin()+((page-1)*8+7)));     // 在卡组数组中添加单张

        // 更新页面当前卡牌数量
        // QString::number 将整型转换成字符串
        QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
        ui->label_size->setText(size);

        // 更新卡组按钮文本
        text.push_back((card.begin()+((page-1)*8+7))->return_name());

        // 应用卡组按钮文本
        update_text();
    }
    m_clicked_time[7]=0;
}

void collectionWindow::but_card_clicked()     // 点击开始计时：确定进行了几次点击
{
    QString btnName = QObject::sender()->objectName();
    int index = (btnName.mid(btnName.size()-1,1)).toInt();

    for(int i=0; i<10; ++i)
    {
        if((index-1) == i)
        {
            m_clicked_time[i]++;
            m_cTime[i].start(200);
        }
    }
}

void collectionWindow::connect_cards()  // 卡组按钮关联
{
    // 初始化 30个卡组按钮
    butCards[0] = ui->pushButton_cards01;
    butCards[1] = ui->pushButton_cards02;
    butCards[2] = ui->pushButton_cards03;
    butCards[3] = ui->pushButton_cards04;
    butCards[4] = ui->pushButton_cards05;
    butCards[5] = ui->pushButton_cards06;
    butCards[6] = ui->pushButton_cards07;
    butCards[7] = ui->pushButton_cards08;
    butCards[8] = ui->pushButton_cards09;
    butCards[9] = ui->pushButton_cards10;
    butCards[10] = ui->pushButton_cards11;
    butCards[11] = ui->pushButton_cards12;
    butCards[12] = ui->pushButton_cards13;
    butCards[13] = ui->pushButton_cards14;
    butCards[14] = ui->pushButton_cards15;
    butCards[15] = ui->pushButton_cards16;
    butCards[16] = ui->pushButton_cards17;
    butCards[17] = ui->pushButton_cards18;
    butCards[18] = ui->pushButton_cards19;
    butCards[19] = ui->pushButton_cards20;
    butCards[20] = ui->pushButton_cards21;
    butCards[21] = ui->pushButton_cards22;
    butCards[22] = ui->pushButton_cards23;
    butCards[23] = ui->pushButton_cards24;
    butCards[24] = ui->pushButton_cards25;
    butCards[25] = ui->pushButton_cards26;
    butCards[26] = ui->pushButton_cards27;
    butCards[27] = ui->pushButton_cards28;
    butCards[28] = ui->pushButton_cards29;
    butCards[29] = ui->pushButton_cards30;

    for(int i=0; i<30; ++i)
    {
        connect(butCards[i], SIGNAL(clicked()), this, SLOT(Button_cards_clicked()));
    }

}

void collectionWindow::Button_cards_clicked()    // 卡组按钮槽
{
    // 点击表示取消卡组中的一张牌
    // 修改对应按钮文本
    // 修改后续按钮文本（全部前移一位）
    QString btnName = QObject::sender()->objectName();  // 获取按钮对象名
    unsigned index = (btnName.mid(btnName.size()-2,2)).toInt();  // 拆分对象名，区分是哪个按钮

    if (text.size() < index)    // 如果点击的按钮没有对应卡牌，结束槽函数
    {
        return;
    }

    cards.out(index-1); // 移出卡牌

    text.erase(text.begin()+index-1);   // 删除对应下标的文本
    update_text();  // 刷新按钮文本
    butCards[cards.size_cards()]->setText(""); // 将最后一个按钮文本清空


    // 更新页面当前卡牌数量
    // QString::number 将整型转换成字符串
    QString size = "卡牌数量" + QString::number(cards.size_cards()) + "/30";
    ui->label_size->setText(size);

}
/********************************* 工具函数 *********************************************************/
void collectionWindow::update_image() // 初始化八张图片
{
    // 根据 card_id使用对应图片初始化
    QIcon myicon; //新建QIcon对象
    for(int i=0; i<8; ++i)
    {
        QString name = (card.begin()+((page-1)*8+i))->return_id();
        QString url = ":/image/calssic/" + name +".png";   // 拼接地址

        // page*8+i page是在收藏中的页面数（所有卡牌 8张一段 分段以后的下标）+i 是在当前页的下标
        myicon.addFile(url); //让QIcon对象指向想要的图标
        butCard[i]->setIcon(myicon); //给按钮添加图标
        butCard[i]->setIconSize(QSize(174,298));//重置图标大小
    }
}

void collectionWindow::update_text()   // 刷新所有卡组按钮的文本
{
    for (int i=0; i<cards.size_cards(); ++i)   // 将所有按钮（有文本）刷新
    {
        butCards[i]->setText(*(text.begin()+i));
    }
}

void collectionWindow::on_pushButton_back_clicked()   // 返回按钮
{
    this->close();

    // 关闭界面时唤起主界面
    mainWindow * mainWin = new mainWindow;
    mainWin->show();
}
