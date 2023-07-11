#ifndef SENDSTRUCT_H
#define SENDSTRUCT_H

#include <QObject>

class sendStruct : public QObject
{
    Q_OBJECT

public:
    int  Type;//用于区分发送的不同内容的数据，对应不同的解析方法
    QString Description;//发送内容的描述
    QByteArray ByteData;//具体发送或者接受的内容，可以将所有基本类型int，char，vector，map等或者自定义的结构体通过
                        //QDataStream序列化到ByteData中，接收端同样的方法从QDataStream中解析出来原数据

public:
    sendStruct();
    explicit sendStruct(int Type,QString Description,QByteArray ByteData=QByteArray(0));

    int size();
    int size() const;

    sendStruct& operator=(const sendStruct &other);

#ifndef QT_NO_DATASTREAM
    friend QDataStream& operator <<(QDataStream& out,const sendStruct& senstruct)
        {
            out<<senstruct.Type
               <<senstruct.Description
               <<senstruct.ByteData;
            return out;
        }
    friend QDataStream& operator >>(QDataStream& in,sendStruct& senstruct)
        {
            in>>senstruct.Type
              >>senstruct.Description
              >>senstruct.ByteData;
            return in;
        }
#endif
};
#endif // SENDSTRUCT_H
