#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

void cargaPilaRandom(Pila*k);
void pasaPila(Pila* k, Pila*l);
int cuentaElementosPila(Pila l);
int sumaElementosPila(Pila l);


int main()
{
    Pila origen, destino;
    inicpila (&origen);
    inicpila (&destino);

    cargaPilaRandom(&origen);

    printf("Pila origen:\n");
    mostrar(&origen);

    int cantidad=cuentaElementosPila(origen);
    printf(" Cantidad elementos: %d \n", cantidad);

    int total=sumaElementosPila(origen);
    printf(" Suma elementos: %d \n", total);

    pasaPila(&origen, &destino);
    printf("Pila origen final:\n");
    mostrar(&origen);
    printf("Pila destino:\n");
    mostrar(&destino);


    return 0;
}

void cargaPilaRandom(Pila* k)
{
    int numero;
    srand(time(NULL));

    for (int i = 0; i < 50; i++){
        numero = rand()%100+1;
        apilar(k, numero);
    }
}

void pasaPila(Pila*k, Pila*l){
    while(!pilavacia(k)){
    apilar(l, desapilar(k));
    }
}

int cuentaElementosPila(Pila l){
    int contador = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l)){
        apilar(&aux, desapilar(&l));
        contador++;
    }
    return contador;
}

int sumaElementosPila(Pila l){
    int acumulador = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l)){
        int topepila;
        topepila = tope(&l);
        acumulador = acumulador + topepila;
        apilar(&aux, desapilar(&l));
    }
    return acumulador;
}



//
