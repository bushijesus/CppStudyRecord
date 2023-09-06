#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include "mylineedit.h"

namespace Ui {
class testMainWindow;
}

class testMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit testMainWindow(QWidget *parent = 0);
    ~testMainWindow();
    bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent *event); // 鼠标按下事件
    void mouseMoveEvent(QMouseEvent *event); // 鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *event); // 鼠标释放事件
    void mouseDoubleClickEvent(QMouseEvent *event); // 鼠标双击事件
    void wheelEvent(QWheelEvent *event);    // 滚轮事件
private slots:
    void showTime();
    void moveWindow();
protected:
    void keyPressEvent(QKeyEvent * event);
private:
    Ui::testMainWindow *ui;
    MyLineEdit* m_lineEdit;
    QPoint offset;
};

#endif // TESTMAINWINDOW_H
