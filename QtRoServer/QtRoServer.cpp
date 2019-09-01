#include "QtRoServer.h"

QtRoServer::QtRoServer(QObject* parent)
    : CommInterfaceSource(parent)
{
    //connect(this, SIGNAL(sig_sendMsgNotify(QString)), this, SLOT(slot_serverReceiveNotifyMsg(QString)));
}

void QtRoServer::slot_receiveMsgNotify(QString strMsgNotify)
{
    qDebug() << strMsgNotify;
}
