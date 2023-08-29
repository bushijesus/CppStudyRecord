#include "set.h"
#include "ui_set.h"
#include <QMovie>
#include <QLabel>

Set::Set(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Set)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie(":/C:/Users/Administrator/Desktop/QQimage/bgi.gif");
    ui->label->setMovie(movie);
    movie->start();
}

Set::~Set()
{
    delete ui;
}

void Set::on_pushButton_clicked()
{
    this->hide();
    emit showMainFromSet();
}

void Set::on_pushButton_2_clicked()
{
    this->hide();
    emit showMainFromSet();
}
