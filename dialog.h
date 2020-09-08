#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include "mythread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    MyThread *mThread;

private:
    Ui::Dialog *ui;

public slots:
    void onValueChanged(int);

private slots:
    // for Start button
    void on_pushButton_clicked();

    // for Stop button
    void on_pushButton_2_clicked();
};

#endif // DIALOG_H
