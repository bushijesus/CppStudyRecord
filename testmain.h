#ifndef TESTMAIN_H
#define TESTMAIN_H

#include <QMainWindow>
#include "calcmultithread.h"
#include <QThread>

namespace Ui {
class testMain;
}

class testMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit testMain(QWidget *parent = 0);
    ~testMain();
private:
    Ui::testMain *ui;
private:
    void calcAddSingleThread(long long int num);
    calcMultiThread* m_thread;
    QThread* main_thread;
private slots:
    void output();

};

#endif // TESTMAIN_H
