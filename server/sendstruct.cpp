#include "sendstruct.h"

sendStruct::sendStruct()
{
    Type=0;
    Description="";
    ByteData=QByteArray(0);
}

int sendStruct::size()
{
    int size=0;
    size=sizeof(int)+Description.size()*2+4+ByteData.size()+4;
    //序列化后QString大小为原有大小乘以2加4，QByteArry序列化后大小为原始大小加4，QString为Unicode编码每个字符占两个字节,
    //QString和QByteArry序列化过程中，首先序列化了本身大小的整形数据(qint32)到序列中，然后才是具体数据。
    return size;
}

int sendStruct::size() const
{
    int size=0;
    size=sizeof(int)+Description.size()*2+4+ByteData.size()+4;
    return size;
}

sendStruct& sendStruct::operator=(const sendStruct &other)
{
    Type=other.Type;
    Description=other.Description;
    ByteData=QByteArray(other.ByteData);
    return *this;
}
