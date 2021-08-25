#include <QCoreApplication>
#include "serveurtcp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServeurTCP monServeur;

    /*monServeur.demandeConnexion();
    monServeur.lecture();*/

    return a.exec();
}
