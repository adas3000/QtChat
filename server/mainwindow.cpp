#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setNickDialog();

    socket = new Socket;
    connect(socket,SIGNAL(userslist(QVector<QString>)),this,SLOT(setUsersList(QVector<QString>)));
    wholeTalk="";
    connect(socket,SIGNAL(newMessage(QString)),this,SLOT(newMessage(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::send()
{
    socket->write(ui->lineEdit->text());
    wholeTalk += ui->lineEdit->text();
    wholeTalk += '\n';
    ui->textBrowser_talk->setText(wholeTalk);
    ui->lineEdit->setText("");
    qDebug () <<"Socket descriptor :"<< socket->GetSocketDescriptor();
}

void MainWindow::setNickDialog()
{
    this->hide();
    nd = new N_Dialog(this);
    nd->setGeometry(this->width(),this->height(),nd->width(),nd->height());
    connect(nd,SIGNAL(nicknameWritten(QString)),this,SLOT(setNickName(QString)));
    nd->setModal(true);
    nd->show();
}

void MainWindow::newMessage(QString message)
{
    wholeTalk+=message;
    wholeTalk+='\n';
    ui->textBrowser_talk->setText(wholeTalk);
}

void MainWindow::setNickName(QString n)
{
    this->nickname = n;
    this->show();
    nd->close();
    QMessageBox::information(this,"Nick","Your nickname is : "+nickname);
    socket->writenickname(nickname);
    ui->label_nickname->setText(nickname);
    delete nd;
}

void MainWindow::setUsersList(QVector<QString> List)
{

}
