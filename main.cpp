#include "qqmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQMain w;
    w.show();

    return a.exec();
}
