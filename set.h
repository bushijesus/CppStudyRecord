#ifndef SET_H
#define SET_H

#include <QMainWindow>

namespace Ui {
class Set;
}

class Set : public QMainWindow
{
    Q_OBJECT
signals:
    void showMainFromSet();

public:
    explicit Set(QWidget *parent = 0);
    ~Set();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Set *ui;
};

#endif // SET_H
