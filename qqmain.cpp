#include "qqmain.h"
#include "ui_qqmain.h"
#include <QMovie>
#include <QLabel>
#include <string>
#include <regex>
#include <QMessageBox>
using namespace std;

QQMain::QQMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QQMain)
{
    ui->setupUi(this);
    m_set = new Set(this);
    m_code = new Code(this);
    connect(m_code, QOverload<>::of(&Code::showMainFromCode),
            this, QOverload<>::of(&QQMain::showMainPage));
    connect(m_set, QOverload<>::of(&Set::showMainFromSet),
            this, QOverload<>::of(&QQMain::showMainPage));

    ui->lineEdit->setPlaceholderText("QQ号码/手机/邮箱");
    ui->lineEdit_2->setPlaceholderText("密码");

    QMovie *movie = new QMovie(":/C:/Users/Administrator/Desktop/QQimage/bc.gif");
    ui->label_3->setMovie(movie);
    movie->start();


}

QQMain::~QQMain()
{
    delete ui;
    delete m_set;
    delete m_code;
}

void QQMain::showMainPage()
{
    m_code->hide();
    this->show();
}

void QQMain::on_pushButton_clicked()
{
    std::string username = ui->lineEdit->text().toStdString();
    std::string password = ui->lineEdit_2->text().toStdString();
    if(username.empty() || !std::regex_match(username, regex("\\d{6,10}")))
    {
        QMessageBox::critical(this, "error", "QQ号码格式错误");
        ui->lineEdit->setFocus();
        return;
    }
    if(password.empty() || !std::regex_match(password, regex("\S{1,16}")))
    {
        QMessageBox::critical(this, "error", "密码格式错误");
        ui->lineEdit_2->setFocus();
        return;
    }
    QMessageBox::information(this, "ok", "登录成功");
}

void QQMain::on_pushButton_2_clicked()
{
    this->hide();
    m_code->show();
}

void QQMain::on_pushButton_3_clicked()
{
    this->hide();
    m_set->show();
}

void QQMain::on_pushButton_4_clicked()
{
    this->hide();
}

void QQMain::on_pushButton_5_clicked()
{
    this->hide();
}
