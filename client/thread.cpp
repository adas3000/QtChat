#include "thread.h"

Thread::Thread(int socketD, QThread *parent) : QThread(parent)
{
    this->socketDescriptor = socketD;
    socket = new QTcpSocket;
    socket->setSocketDescriptor(this->socketDescriptor);
    nickname = "";
}

void Thread::run()
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(readData()),Qt::DirectConnection);
}

void Thread::sendonlineusers(QVector<QString> nicknames)
{
    QString full = "111111111";
    full+='\n';
    for(int i=0 ; i<nicknames.size() ;i++)
    {
        full+=nicknames[i].toLatin1();
        full+='\n';
       // socket->write(nicknames[i].toLatin1());
    }
    socket->write(full.toLatin1());
}

void Thread::readData()
{
    QString message = QString(socket->readAll());
    if(message[0]=='0')
    {
        if(message[1] == '7' && message[2] == '7' && message[3]=='0')
        {
            for(int i=4 ;i<message.size() ; i++)
                nickname+=message[i];
        }
    }
    emit someonesays(nickname,message);
   // qDebug () << message;
}
