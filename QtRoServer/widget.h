#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

#include "QtRoServer.h"
#include <QThread>

class ServerWorkThread : public QThread
{
public:
    ServerWorkThread(QtRoServer* pServer) { m_pServer = pServer; }
    void run() override
    {
        ;
    }

private:
    QtRoServer* m_pServer;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QtRoServer m_server;

private slots:
    void slot_receiveMsg(QString strMsg);
};

#endif // WIDGET_H
