#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QVector>


class Socket : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
public:
    explicit Socket(QObject *parent = nullptr);
    void write(QString);
    void writenickname(QString &);
    int GetSocketDescriptor(){return socket->socketDescriptor(); }
signals:
    void newMessage(QString);
    void userslist(QVector<QString>);
public slots:
    void readData();
};

#endif // SOCKET_H
