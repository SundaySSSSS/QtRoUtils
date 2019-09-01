#ifndef QTROSERVER_H
#define QTROSERVER_H

#include "rep_CommInterface_source.h"

class QtRoServer : public CommInterfaceSource
{
    Q_OBJECT

    /* 对外接口 */
public:
    QtRoServer(QObject* parent = nullptr);
    virtual ~QtRoServer();

    QByteArray QtRoData() const { return m_baQtRoData; }
    void setQtRoData(QByteArray data) { m_baQtRoData = data; }
    void sendMsg(QString strMsg) { emit sig_sendMsg(strMsg); }

Q_SIGNALS:
    void sig_receiveMsgFromClient(QString strMsg);
    /* 对外接口结束 */

Q_SIGNALS:
    //void sig_sendMsgFromServer(QString strMsg);

private Q_SLOTS:
    void slot_receiveMsg(QString strMsg);
private:
    QByteArray m_baQtRoData;
    QRemoteObjectHost* m_pSrcNode;
};

#endif // QTROSERVER_H
