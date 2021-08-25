#include "carton.h"
#include <iostream>

Carton::Carton()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<9;j++)carton[i][j]=0;

}

Carton::~Carton()
{

}

void Carton::Remplir()
{
    //remplissage du carton

    //initialisation du générateur

    srand(time(NULL));

        //remplissage 1er
    unsigned int indice;

    for(int compt=0;compt<5;compt++)
    {
    indice = rand()%9; //plage entre 0 et 8
    while(carton[0][indice]!=0)
    {

        indice = rand()%9;

    }
    carton[0][indice]=indice*10+(rand()%9);

    }
        //remplissage 2eme
    int test = 0;


    for(int compt=0;compt<5;compt++)
    {
    indice = rand()%9; //plage entre 0 et 8
    while(carton[1][indice]!=0 && test<4)
    {
        if(carton[0][indice]!=0)
        {
            test++;
        }
        indice = rand()%9;

    }
    carton[1][indice]=indice*10+(rand()%9);
    while(carton[1][indice]==carton[0][indice])
    carton[1][indice]=indice*10+(rand()%9);

    }
        //remplissage 3eme

    int taille = 5;

    for(int k=0; k<9; k++)
    {
        if(carton[0][k]==0 && carton[1][k]==0)
        {
            carton[2][k]=k*10+(rand()%11);
            while(carton[2][k]==carton[0][k] || carton[2][k]==carton[1][k])
            carton[2][k]=k*10+(rand()%11);
            taille--;
        }
    }

    for(int compt=0;compt<taille;compt++)
    {
    indice = rand()%9; //plage entre 0 et 8
    while((carton[1][indice]!=0 && carton[0][indice]!=0) || (carton[2][indice]!=0))
    {
        indice = rand()%9;

    }
    carton[2][indice]=indice*10+(rand()%11);
    while(carton[2][indice]==carton[0][indice] && carton[2][indice]==carton[1][indice])
    carton[1][indice]=indice*10+(rand()%9);

    }
}

unsigned int Carton::GetCarton(int ligne, int colonne)
{
    return carton[ligne][colonne];
}
