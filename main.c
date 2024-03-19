#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

void cargaPilaRandom(Pila* k);
void muestraPilaRandom (Pila k);


int main()
{
    Pila tempLondon;
    inicpila (&tempLondon);

    cargaPilaRandom(&tempLondon);

    printf("Muestra temperaturas de Londres en verano: \n");
    //Las temperaturas promedio en verano son entre 10 y 23°C.
    muestraPilaRandom(tempLondon);

    return 0;
}

void cargaPilaRandom(Pila* k)
{
    int numero;
    srand(time(NULL));

    for (int i = 1; i < 50; i++)
    {
        numero = rand()%23+10;
        apilar(k, numero);
    }
}

void muestraPilaRandom(Pila k)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&k))
    {
        printf("%d - ", tope(&k));
        apilar(&aux, desapilar(&k));
    }
}
