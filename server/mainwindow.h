#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "n_dialog.h"
#include "socket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void send();
    void setNickDialog();
private slots:
    void on_lineEdit_returnPressed(){send();}

    void on_pushButton_send_clicked(){send();}
    void newMessage(QString);
public slots:
    void setNickName(QString);
    void setUsersList(QVector<QString>List);
private:
    Ui::MainWindow *ui;
    Socket *socket;
    QString wholeTalk;
    QString nickname;
    N_Dialog *nd;
};

#endif // MAINWINDOW_H
