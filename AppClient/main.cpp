#include <QCoreApplication>
#include "clienttcp.h"
#include "carton.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ClientTcp monClient;


    return a.exec();
}
