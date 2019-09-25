#include "n_dialog.h"
#include "ui_n_dialog.h"

N_Dialog::N_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::N_Dialog)
{
    ui->setupUi(this);
}

N_Dialog::~N_Dialog()
{
    delete ui;
}

void N_Dialog::on_pushButton_clicked()
{
    this->nickname = ui->lineEdit->text();
    emit nicknameWritten(nickname);
}
