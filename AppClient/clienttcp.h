#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QObject>
#include <QTcpSocket>
#include "carton.h"

class ClientTcp : public QObject
{
    Q_OBJECT
public:
    explicit ClientTcp(QObject *parent = 0);

public slots:

    void connexionOk();
    void lecture();

private:
    QTcpSocket *socketClient;
};

#endif // CLIENTTCP_H
