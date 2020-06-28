/*
Autor: Tomas Bravo
Tipo de Solucion:

Escriba la función void ordenParcial(int* v1, int n, int cant) que recibe un vector de enteros v1, 
su tamaño n y un número entero cant y modifica el vector v1 de tal manera que las primeras cant 
posiciones contengan los cant números más grandes de v1 y éstos se encuentren ordenados ascendentemente. 
v1 deberá mantener todos los elementos inicialmente almacenados, sólo cambiar su posición para que se 
cumpla el invariante antes descrito.
*/
#include <stdio.h>

void Swap(int *n1, int *n2);

void ordenParcial(int *v, int n, int cant)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] < v[j])
            {
                Swap(&v[i], &v[j]);
            }
        }
    }

    for (int i = 0; i < cant - 1; i++)
    {
        for (int j = i + 1; j < cant; j++)
        {
            if (v[i] > v[j])
            {
                Swap(&v[i], &v[j]);
            }
        }
    }
}

void Swap(int *n1, int *n2)
{
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}