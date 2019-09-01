#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

#include "QtRoClient.h"
#include <QThread>

class ClientWorkThread : public QThread
{
public:
    ClientWorkThread(QtRoClient* pClient)
    {
        m_pClient = pClient;
    }
    void run() override
    {
        if (m_pClient == nullptr)
        {
            return;
        }
        while (1)
        {
            qDebug() << "send Msg to server";
            m_pClient->sendMsgNotify("123");
            sleep(1);
        }
    }
private:
    QtRoClient* m_pClient;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QtRoClient m_client;
    ClientWorkThread* m_pWorkThread;
};

#endif // WIDGET_H
