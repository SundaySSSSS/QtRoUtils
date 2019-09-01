#ifndef QTROSERVER_H
#define QTROSERVER_H

#include "rep_CommInterface_source.h"

class QtRoServer : public CommInterfaceSource
{
    Q_OBJECT
public:
    QtRoServer(QObject* parent = nullptr);
    virtual ~QtRoServer();

    QByteArray msg() const { return m_baMsg; }
    void setMsg(QByteArray msg) { m_baMsg = msg; }

private Q_SLOTS:
    void slot_receiveMsgNotify(QString strMsgNotify);
private:
    QByteArray m_baMsg;
    QRemoteObjectHost* m_pSrcNode;
};

#endif // QTROSERVER_H
