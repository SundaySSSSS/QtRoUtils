#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");
    m_pSrcNode = new QRemoteObjectHost(QUrl(QStringLiteral("local:switch"))); // create host node without Registry
    m_pSrcNode->enableRemoting(&m_server); // enable remoting/sharing
}

Widget::~Widget()
{
    delete ui;
}
