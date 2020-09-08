#include "dialog.h"
#include "ui_dialog.h"
#include "mythread.h"
#include <qmovie.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // create an instance of MyThread
    mThread = new MyThread(this);

    // connect signal/slot
    connect(mThread, SIGNAL(valueChanged(int)),
            this, SLOT(onValueChanged(int)));

}

Dialog::~Dialog()
{
    delete ui;
}

// Absorb the signal emitted from a run() method
// and reflect the count change to the count label
// in our dialog

void Dialog::onValueChanged(int count)
{
    ui->label->setText(QString::number(count));
}

// Start button
void Dialog::on_pushButton_clicked()
{
    mThread->start();
    //QLabel *lbl = new QLabel;
    QMovie *movie = new QMovie("/home/pi/loader1.gif");
    ui->label_2->setMovie(movie);
    //lbl->show();
    movie->start();


}

// Stop button
void Dialog::on_pushButton_2_clicked()
{
    mThread->Stop = true;
    ui->label_2->hide();

}
