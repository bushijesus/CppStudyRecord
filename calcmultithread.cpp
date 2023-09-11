#include "calcmultithread.h"

calcMultiThread::calcMultiThread(QObject *parent) : QObject(parent)
{

}
void calcMultiThread::calcAdd1MultiThread1()
{
    int sum = 0;
    for(int i = 0; i < 1000000000; i += 5)
    {
        sum += i;
    }
    totalsum += sum;
    emit calcFinish();
}

void calcMultiThread::calcAdd1MultiThread2()
{
    int sum = 0;
    for(int i = 1; i <= 1000000000; i += 5)
    {
        sum += i;
    }
    totalsum += sum;
    emit calcFinish();
}

void calcMultiThread::calcAdd1MultiThread3()
{
    int sum = 0;
    for(int i = 2; i <= 1000000000; i += 5)
    {
        sum += i;
    }
    totalsum += sum;
    emit calcFinish();
}

void calcMultiThread::calcAdd1MultiThread4()
{
    int sum = 0;
    for(int i = 3; i <= 1000000000; i += 5)
    {
        sum += i;
    }
    totalsum += sum;
    emit calcFinish();
}

void calcMultiThread::calcAdd1MultiThread5()
{
    int sum = 0;
    for(int i = 4; i <= 1000000000; i += 5)
    {
        sum += i;
    }
    totalsum += sum;
    emit calcFinish();
}
