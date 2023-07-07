#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server();
    ~Server();

    void on_Send();    // 发送消息
    void on_DisConnect();    // 断开链接
    void on_Connect(QString addr, qint16 port);    // 链接:addr是ip，port是端口

private slots:

    void onConnected();    // 处理链接
    void onDisConnected();    // 处理断开
    void onStateChanged(QAbstractSocket::SocketState);    // 链接状态修改

    void onReadyRead();    // 读取信息

private:

    QTcpSocket *m_tcpSocket = nullptr;


};

#endif // SERVER_H
