#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QLineEdit>
#include <QWheelEvent>

testMainWindow::testMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testMainWindow)
{
    ui->setupUi(this);
    m_lineEdit = new MyLineEdit(this);
    m_lineEdit->move(100, 100);
    m_lineEdit->installEventFilter(this);

    ui->label->installEventFilter(this);
    ui->label_2->installEventFilter(this);
    ui->label_3->installEventFilter(this);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moveWindow()));
    timer->start(3000);
}

testMainWindow::~testMainWindow()
{
    delete ui;
}

bool testMainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == m_lineEdit){
        if(event->type() == QEvent::KeyPress){
            qDebug()<<tr("MainWindow键盘按下事件");
        }
    }
    if(obj == ui->label){
        if(event->type() == QEvent::MouseButtonPress){
            qDebug()<<"红";
        }
    }
    if(obj == ui->label_2){
        if(event->type() == QEvent::MouseButtonPress){
            qDebug()<<"绿";
        }
    }
    if(obj == ui->label_3){
        if(event->type() == QEvent::MouseButtonPress){
            qDebug()<<"蓝";
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void testMainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    }
    else if(event->button() == Qt::RightButton){
        QCursor cursor(QPixmap(":/C:/Users/Administrator/Desktop/ClusterChat.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void testMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QPoint tmp;
        tmp = event->globalPos()-offset;
        move(tmp);
    }
}

void testMainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::restoreOverrideCursor();
}

void testMainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(windowState() != Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else
        {
            setWindowState(Qt::WindowNoState);
        }
    }
}

void testMainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        ui->textEdit->zoomIn();
    }
    else
    {
        ui->textEdit->zoomOut();
    }
}

void testMainWindow::showTime()
{
    QTime curtime = QTime::currentTime();
    QString str = curtime.toString("hh:mm:ss");
    qDebug()<<str;
}

void testMainWindow::moveWindow()
{
    QPoint globalPos = this->mapToGlobal(QPoint(0, 0));
    this->move(globalPos.x() + 5, globalPos.y() + 10);
}



void testMainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<tr("MainWindow键盘按下事件");
}
