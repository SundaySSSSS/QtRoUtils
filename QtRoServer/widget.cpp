#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");
    connect(&m_server, SIGNAL(sig_receiveMsgFromClient(QString)),
            this, SLOT(slot_receiveMsg(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_receiveMsg(QString strMsg)
{
    qDebug() << "server receive msg:" << strMsg;
    qDebug() << "send back echo";
    m_server.sendMsg(strMsg);
}
