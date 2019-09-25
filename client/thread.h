#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class Thread : public QThread
{
    Q_OBJECT
private:
    int socketDescriptor;
    QTcpSocket *socket;
    QString nickname;
public:
    explicit Thread(int socketD,QThread *parent = nullptr);
    void run();
    void sendMessage(QString message) {socket->write(message.toLatin1());}
    void setNickName(QString nick) {nickname = nick;}
    void sendonlineusers(QVector<QString>nicknames);
    int GetSocketDescriptor(){return socket->socketDescriptor();}
    QString GetNickName(){return nickname;}
signals:
    void someonesays(QString nick,QString message);
public slots:
    void readData();
};

#endif // THREAD_H
