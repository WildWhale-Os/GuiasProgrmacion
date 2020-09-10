/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba la función void ordenParcial(int* v1, int n, int cant) que recibe un vector de enteros v1, 
su tamaño n y un número entero cant y modifica el vector v1 de tal manera que las primeras cant 
posiciones contengan los cant números más grandes de v1 y éstos se encuentren ordenados ascendentemente. 
v1 deberá mantener todos los elementos inicialmente almacenados, sólo cambiar su posición para que se 
cumpla el invariante antes descrito.
*/
#include <stdio.h>

void Swap(int *n1, int *n2); // definimos una funcion para hacer intercambios de numeros

void ordenParcial(int *v, int n, int cant) // declaramos la funcion de ordenParcial
{
    for (int i = 0; i < n - 1; i++) // esta funcion recorrera el arreglo entregado
    {
        for (int j = i + 1; j < n; j++) // dos veces
        {
            if (v[i] < v[j]) // comparando dos numeros y viendo si el siguiente al actual es mayor o no
            {
                Swap(&v[i], &v[j]); // si es mayor cambia los valores en las posiciones
            }
        }
    }

    for (int i = 0; i < cant - 1; i++) // luego recorre solo la cantidad de nuemeros que tenina que ser ordenados de menor a mayor que son la cant de numeros mas grandes del arreglo
    {
        for (int j = i + 1; j < cant; j++) // y recorre una segunda vez
        {
            if (v[i] > v[j]) // para comparar dos numeros del arreglo buscando que los menores de la cant de numeros mayores esten al inicio del arreglo
            {
                Swap(&v[i], &v[j]); // si un numero es mas chico que otro y se encuentre a su drecha cambia sus posiciones
            }
        }
    }
}

void Swap(int *n1, int *n2) // definicion de la funcion Swap
{
    int aux = *n1; // declara una variable auxiliar que es igual a uno de los dos numeros entregados por referencia
    *n1 = *n2;     // luego cambia los valores de los valores entregados entre si
    *n2 = aux;
}