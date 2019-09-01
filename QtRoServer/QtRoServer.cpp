#include "QtRoServer.h"

QtRoServer::QtRoServer(QObject* parent)
    : CommInterfaceSource(parent)
{
    m_pSrcNode = new QRemoteObjectHost(QUrl(QStringLiteral("local:switch")));
    m_pSrcNode->enableRemoting(this);
}

QtRoServer::~QtRoServer()
{
    m_pSrcNode->disableRemoting(this);
    delete m_pSrcNode;
    m_pSrcNode = nullptr;
}

void QtRoServer::slot_receiveMsg(QString strMsg)
{
    emit sig_receiveMsgFromClient(strMsg);
}
