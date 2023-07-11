#include "server.h"

#include <QHostAddress>

Server::Server()
{
    m_tcpSocket = new QTcpSocket();

    connect(m_tcpSocket,&QTcpSocket::connected,this,&Server::onConnected);
    connect(m_tcpSocket,&QTcpSocket::disconnected,this,&Server::onDisConnected);
    connect(m_tcpSocket,&QTcpSocket::stateChanged,this,&Server::onStateChanged);
    connect(m_tcpSocket,&QTcpSocket::readyRead,this,&Server::onReadyRead);
}

Server::~Server()
{

}

void Server::on_Connect(QString addr, qint16 port)    // 链接服务器:addr是ip，port是端口
{
    m_tcpSocket->connectToHost(addr,port);
    qDebug() << "服务器" << addr << ":" << port;
}

void Server::on_Send(QString msg)    // 发送信息
{
    // 执行下发
    QByteArray str = msg.toUtf8();
    str.append('\n');
    qDebug() << m_tcpSocket->write(str);
}

void Server::on_DisConnect()    // 断开连接
{
    if(m_tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        m_tcpSocket->disconnectFromHost();
    }
    qDebug() << "断开连接";
}

void Server::onConnected()    // 得到服务器链接结果
{
    qDebug() << "链接到服务器";
    qDebug() << ("地址: " + m_tcpSocket->peerAddress().toString());
    qDebug() << ("端口: " + QString::number(m_tcpSocket->peerPort()));
}

void Server::onDisConnected()    // 断开服务器链接
{
    qDebug() << ("**已断开服务器");
}

void Server::onStateChanged(QAbstractSocket::SocketState)    // 链接状态修改
{
    qDebug("状态修改");
}

void Server::onReadyRead()    // 接受信息
{
    while(m_tcpSocket->canReadLine())
    {
        QString in = m_tcpSocket->readLine();
        qDebug() << ("[in]：" + in);
    }
}
