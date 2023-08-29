#ifndef CODE_H
#define CODE_H

#include <QMainWindow>

namespace Ui {
class Code;
}

class Code : public QMainWindow
{
    Q_OBJECT
signals:
    void showMainFromCode();
public:
    explicit Code(QWidget *parent = 0);
    ~Code();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Code *ui;
};

#endif // CODE_H
