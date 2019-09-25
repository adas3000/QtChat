#ifndef N_DIALOG_H
#define N_DIALOG_H

#include <QDialog>

namespace Ui {
class N_Dialog;
}

class N_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit N_Dialog(QWidget *parent = 0);
    ~N_Dialog();

private slots:
    void on_pushButton_clicked();

signals:
    void nicknameWritten(QString);
private:
    Ui::N_Dialog *ui;
    QString nickname;
};

#endif // N_DIALOG_H
