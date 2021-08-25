#ifndef CARTON_H
#define CARTON_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Carton
{
    unsigned int carton[3][9];
public:
    Carton();
    ~Carton();
    void Remplir();
    unsigned int GetCarton(int ligne, int colonne);
};

#endif // CARTON_H
