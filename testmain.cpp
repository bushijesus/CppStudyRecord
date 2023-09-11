#include "testmain.h"
#include "ui_testmain.h"
#include <QDebug>
#include <QCoreApplication>
#include <QElapsedTimer>

long long int totalsum = 0;

testMain::testMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testMain)
{
    ui->setupUi(this);

    QElapsedTimer timer;
    timer.start();

    calcAddSingleThread(1000000000);

    qint64 elapsedTime = timer.elapsed();
    qDebug() << "耗时：" << elapsedTime << "毫秒";

    main_thread = new QThread;
    m_thread = new calcMultiThread;
    m_thread->moveToThread(main_thread);
    connect(main_thread, SIGNAL(started()), m_thread, SLOT(calcAdd1MultiThread1()));
    connect(main_thread, SIGNAL(started()), m_thread, SLOT(calcAdd1MultiThread2()));
    connect(main_thread, SIGNAL(started()), m_thread, SLOT(calcAdd1MultiThread3()));
    connect(main_thread, SIGNAL(started()), m_thread, SLOT(calcAdd1MultiThread4()));
    connect(main_thread, SIGNAL(started()), m_thread, SLOT(calcAdd1MultiThread5()));
    connect(m_thread, SIGNAL(calcFinish()), this, SLOT(output()));
    main_thread->start();
}

testMain::~testMain()
{
    delete ui;
    delete m_thread;
    main_thread->deleteLater();
}

void testMain::calcAddSingleThread(long long int num)
{
    int sum = 0;
    for(int i = 1; i <= num / 2; ++i)
    {
        sum += (1 + num);
    }
    qDebug()<<sum;
}

void testMain::output()
{
    qDebug()<<totalsum;
}


