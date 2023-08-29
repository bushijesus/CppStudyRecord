#ifndef QQMAIN_H
#define QQMAIN_H

#include <QMainWindow>
#include "set.h"
#include "code.h"

namespace Ui {
class QQMain;
}

class QQMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit QQMain(QWidget *parent = 0);
    ~QQMain();
private slots:
    void showMainPage();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::QQMain *ui;
    Set* m_set;
    Code* m_code;
};

#endif // QQMAIN_H
