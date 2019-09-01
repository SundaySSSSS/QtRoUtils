#include "QtRoClient.h"

QtRoClient::QtRoClient(QObject* parent)
    : QObject(parent)
{
    m_repNode.connectToNode(QUrl(QStringLiteral("local:switch")));
    m_pReplica = m_repNode.acquire<CommInterfaceReplica>();
    connect(this, SIGNAL(sig_sendMsgFromClient(QString)), m_pReplica, SLOT(slot_receiveMsg(QString)));
    connect(m_pReplica, SIGNAL(sig_sendMsg(QString)), this, SLOT(slot_receiveMsg(QString)));
}

QtRoClient::~QtRoClient()
{
    ;
}

void QtRoClient::sendMsg(QString strMsg)
{
    emit sig_sendMsgFromClient(strMsg);
}

void QtRoClient::slot_receiveMsg(QString strMsg)
{
    emit sig_receiveMsgFromServer(strMsg);
}
