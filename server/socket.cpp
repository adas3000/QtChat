#include "socket.h"

Socket::Socket(QObject *parent) : QObject(parent)
{
   socket = new QTcpSocket;
   socket->connectToHost("localhost",1234);

   connect(socket,SIGNAL(readyRead()),this,SLOT(readData()));
}

void Socket::write(QString message)
{
    socket->write(message.toLatin1());
}

void Socket::writenickname(QString &n)
{
    socket->write(QByteArray("0770"+n.toLatin1()));
}

void Socket::readData()
{
    QString message = socket->readAll();
    if(message[0]=='1' && message[1]=='1' && message[2] == '1')
    {
        if(message[3]=='1' && message[4] == '1' && message[5]=='1' && message[6] == '1' && message[7] == '1' && message[8] == '1')
        {
            QVector<QString>users;
            users.push_back("");
            int j;
            for(int i=10,j=0 ; i<message.size() ; i++)
            {
                if(message[i]=='\n')
                {
                    users.push_back("");
                    j++;
                }
                else
                    users[j]+=message[i];

            }
            for(int i=0 ; i<users.size() ; i++)
                qDebug () <<"user "<<i+1<<" : "<<users[i];

            emit userslist(users);
        }
    }
    else emit newMessage(message);
}
