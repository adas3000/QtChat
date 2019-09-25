#include "myserver.h"

MyServer::MyServer(QTcpServer *parent) : QTcpServer(parent)
{
    usersCount = 0;
}

void MyServer::start()
{
    if(this->listen(QHostAddress::Any,1234))
    {
    qDebug () << "Server started";
    emit serverStarted();
    }
    else
    {
        qDebug () <<"Eror";
        emit error();
    }
}

QVector<QString> MyServer::setOnLineUsers()
{
    QVector<QString>nicknames;

    for(int i=0 ; i<usersCount ; i++)
        nicknames.push_back(users[i]->GetNickName());

    return nicknames;
}

void MyServer::incomingConnection(int socketDescriptor)
{
    users[usersCount] = new Thread(socketDescriptor);
    users[usersCount]->run();
    connect(users[usersCount],SIGNAL(someonesays(QString,QString)),this,SLOT(someonesays(QString,QString)));
    users[usersCount]->sendonlineusers(setOnLineUsers());
    usersCount++;
    qDebug () <<" New client , socket descriptor : "<<socketDescriptor;
}

void MyServer::someonesays(QString nick, QString message)
{
    qDebug () << nick <<" says : "<<message;
}
