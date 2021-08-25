#include <serveurtcp.h>
#include <iostream>
#include <QString>
//#include <QHostAdress>

using namespace std;

ServeurTCP::ServeurTCP(QObject *parent) :
    QObject(parent)
{

    leServeur=new QTcpServer(this);
    leServeur->listen(QHostAddress::Any, 4444);

    QObject::connect(leServeur,SIGNAL(newConnection()),this,SLOT(demandeConnexion()));
}

void ServeurTCP::demandeConnexion()
{
    cout<<"demande de connexion"<<endl;
    socketClient=leServeur->nextPendingConnection();

    QObject::connect(socketClient,SIGNAL(readyRead()),this,SLOT(lecture()));
    //QObject::connect(socketClient,SIGNAL(readyRead()),this,SLOT(lecture()));

}

void ServeurTCP::lecture()
{
    QString message;

    cout<<"donnees arrivees"<<endl;
    message = socketClient->readAll();
    cout<<message.toStdString();
    this->tirage();
}

void ServeurTCP::tirage()
{
    QByteArray chiffre("12");
    socketClient->write(chiffre);
}
