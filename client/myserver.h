#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QVector>
#include "thread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
private:
    Thread *users[100];
    int usersCount;
public:
    explicit MyServer(QTcpServer *parent = nullptr);
    void start();
private:
    QVector<QString> setOnLineUsers();
protected:
    void incomingConnection(int socketDescriptor);
signals:
    void serverStarted();
    void newUserConnected();
    void error();
public slots:
    void someonesays(QString nick,QString message);
};

#endif // MYSERVER_H
