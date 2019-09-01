#ifndef QTROCLIENT_H
#define QTROCLIENT_H

#include <QObject>

#include "rep_CommInterface_replica.h"

class QtRoClient : public QObject
{
    Q_OBJECT

    /* 对外接口 */
public:
    QtRoClient(QObject* parent = nullptr);
    virtual ~QtRoClient();
    void sendMsg(QString strMsg);

Q_SIGNALS:
    void sig_receiveMsgFromServer(QString strMsg);
    /* 对外接口结束 */

Q_SIGNALS:
    void sig_sendMsgFromClient(QString strMsg);

private Q_SLOTS:
    void slot_receiveMsg(QString strMsg);
private:
    CommInterfaceReplica* m_pReplica;
    QRemoteObjectNode m_repNode;
};

#endif // QTROCLIENT_H
