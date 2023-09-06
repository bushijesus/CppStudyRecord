#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>



class MyLineEdit : public QLineEdit
{
public:
    MyLineEdit(QWidget* parent = 0);
    bool event(QEvent * eve);
protected:
    void keyPressEvent(QKeyEvent * eve);
};

#endif // MYLINEEDIT_H
