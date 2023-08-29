#include "code.h"
#include "ui_code.h"

Code::Code(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Code)
{
    ui->setupUi(this);
}

Code::~Code()
{
    delete ui;
}

void Code::on_pushButton_clicked()
{
    emit showMainFromCode();
}
