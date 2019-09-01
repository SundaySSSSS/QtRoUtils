#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");
    m_pWorkThread = new ClientWorkThread(&m_client);
    connect(&m_client, SIGNAL(sig_receiveMsgFromServer(QString)),
            this, SLOT(slot_receiveMsgFromServer(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_pWorkThread->start();
}

void Widget::slot_receiveMsgFromServer(QString strMsg)
{
    qDebug() << "receive from server" << strMsg;
}
