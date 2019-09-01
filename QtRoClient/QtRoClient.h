#ifndef QTROCLIENT_H
#define QTROCLIENT_H

#include <QObject>

#include "rep_CommInterface_replica.h"

class QtRoClient : public QObject
{
    Q_OBJECT
public:
    QtRoClient(QObject* parent = nullptr);
    virtual ~QtRoClient();
    void sendMsgNotify(QString strMsgNotify);

private:
    CommInterfaceReplica* m_pReplica;
    QRemoteObjectNode m_repNode;

Q_SIGNALS:
    void sig_sendMsgNotifyFromClient(QString strMsgNotify);
};

#endif // QTROCLIENT_H
