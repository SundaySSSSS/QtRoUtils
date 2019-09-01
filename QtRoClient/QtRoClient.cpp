#include "QtRoClient.h"

QtRoClient::QtRoClient(QObject* parent)
    : QObject(parent)
{
    m_repNode.connectToNode(QUrl(QStringLiteral("local:switch")));
    m_pReplica = m_repNode.acquire<CommInterfaceReplica>();
    connect(this, SIGNAL(sig_sendMsgNotifyFromClient(QString)), m_pReplica, SLOT(slot_receiveMsgNotify(QString)));
}

QtRoClient::~QtRoClient()
{
    ;
}

void QtRoClient::sendMsgNotify(QString strMsgNotify)
{
    emit sig_sendMsgNotifyFromClient(strMsgNotify);
}
