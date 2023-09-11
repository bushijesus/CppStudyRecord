#ifndef CALCMULTITHREAD_H
#define CALCMULTITHREAD_H

#include <QObject>

extern long long int totalsum;

class calcMultiThread : public QObject
{
    Q_OBJECT
public:
    explicit calcMultiThread(QObject *parent = nullptr);

signals:
    void calcFinish();
public slots:
    void calcAdd1MultiThread1();
    void calcAdd1MultiThread2();
    void calcAdd1MultiThread3();
    void calcAdd1MultiThread4();
    void calcAdd1MultiThread5();
};

#endif // CALCMULTITHREAD_H
