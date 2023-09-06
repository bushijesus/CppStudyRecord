#include "mylineedit.h"
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>

MyLineEdit::MyLineEdit(QWidget* parent)
    :QLineEdit(parent)
{

}

bool MyLineEdit::event(QEvent *eve)
{
    if(eve->type() == QEvent::KeyPress)
    {
        qDebug()<<tr("MyLineEdit的event()函数");
    }
    return QLineEdit::event(eve);
}

void MyLineEdit::keyPressEvent(QKeyEvent *eve)
{
    qDebug()<<tr("MyLineEdit键盘按下事件");
    QLineEdit::keyPressEvent(eve);     // 默认事件处理函数
    eve->ignore();   // 忽略该事件，才可使事件跳到父部件中
}
