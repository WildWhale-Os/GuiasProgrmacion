/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba una función void modificarMatriz(int n, int m, int mat1[n][m]) que recibe 
una matriz, mat1 y reemplaza todas las apariciones del número 1, por un -1.

*/
#include <stdio.h>
#include <stdlib.h>

void ModificarMatriz(int n, int m, int mat1[n][m]) // definicion de la funcion que modifica la matriz entregada
{
    for (int i = 0; i < n; ++i) // la funcion recorre todas las filas de la matriz
    {
        for (int j = 0; j < m; ++j) // por cada valor dentro de cada fila
        {
            if (mat1[i][j] == 1) // y si encuentra un numero 1
                mat1[i][j] = -1; // lo cambia por un -1
        }
    }
}