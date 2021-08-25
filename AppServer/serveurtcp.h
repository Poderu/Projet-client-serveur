#ifndef SERVEURTCP_H
#define SERVEURTCP_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class ServeurTCP : public QObject
{
    Q_OBJECT
public:
    explicit ServeurTCP(QObject *parent = 0);
    void tirage();

signals:

public slots:
    void demandeConnexion();
    void lecture();


private:
    QTcpServer *leServeur;
    QTcpSocket *socketClient;

};

#endif // SERVEURTCP_H
