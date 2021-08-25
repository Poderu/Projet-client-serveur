#include "clienttcp.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <iostream>

using namespace std;

ClientTcp::ClientTcp(QObject *parent) : QObject(parent)
{

    socketClient= new QTcpSocket(this);

    //cout<<"client "<< socketClient->socketDescriptor()<< endl;


    socketClient->connectToHost("127.0.0.1",4444,QIODevice::ReadWrite,QAbstractSocket::AnyIPProtocol);

    QObject::connect(socketClient,SIGNAL(connected()),this,SLOT(connexionOk()));
    QObject::connect(socketClient,SIGNAL(readyRead()),this,SLOT(lecture()));


}

void ClientTcp::connexionOk()
{

    QByteArray message("bonjour serveur !");

    cout<<"client connecte"<<endl;
    cout<<"envoi d un message au serveur"<<endl;

    socketClient->write(message);

    cout<<"message envoye"<<endl<<endl;

    Carton monCarton;
    monCarton.Remplir();
    for(int i=0;i<3;i++)

    {
        for(int j=0;j<9;j++)
        {
            cout<<monCarton.GetCarton(i,j)<<"\t";
        }
        cout<<"\n\n\n";
    }
}

void ClientTcp::lecture()
{
    QByteArray chiffre;
    int nombre;



    cout<<"***********************************************************************"<<endl;
    cout<<"donnees arrivees"<<endl<<endl;
    chiffre = socketClient->readAll();
    nombre = chiffre.toInt();
    cout<<nombre<<endl;
}
