/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba la función int determinante(int n, int m1[n][n]) que reciba una matriz m1 de tamaño n × n y 
devuelva el determinante de la matriz. El valor de n solo puede ser 2, 3 o 4, en caso de que n tome 
un valor diferente, la función deberá devolver la constante INT MIN.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int SubMatriz(int n, int m1[n][n], int fila, int columna); // declaracion de la funcion Submatriz

int Determinante(int n, int m1[n][n]) // definicion de la funcion determinate
{
    int det = 0;                                              // declaramos una variable entera que contendra el valor de nuestro determiante
    if ((n != 2) && (n != 3) && (n != 4))                     // si el orden de la matriz entregada no es ni 2 o 3 o 4
        return INT_MIN;                                       // esta funcion devolvera el valor de una contante que es el valor mas chico que puede almacenar una variable entera
    if (n == 2)                                               // si es orden de la matriz es 2
        det += (m1[0][0] * m1[1][1]) - (m1[0][1] * m1[1][0]); // se multiplican los valores de la diagonal principal y se resta con la multiplicacion de la diagonal secundaria
    else                                                      // si el orden es 4 o 3
    {
        for (int i = 0; i < n; i++) // se recorre una sola fila de la matriz
        {
            det += m1[0][i] * SubMatriz(n, m1, 0, i); // y se le suma al valor de determinante la multiplicacion de el valor en la primera fila por el valor entregado por la funcion submatriz
        }
    }
    return det; // finalmente devuelve el valor de la vairable det
}

int SubMatriz(int n, int m1[n][n], int fila, int columna) // definicion de la funcion submatriz
{
    int m2[n][n];         // declramos una matriz cuadrada de orden n
    int col = 0, fil = 0; // declaramos dos variables auxiliares para posicionarnos en nuestra matriz auxuliar

    for (int i = 0; i < n; i++) // por cada fila
    {
        for (int j = 0; j < n; j++) // y por cada numero en cada fila
        {
            if (i != fila && j != columna) // buscamos los numeros que no esten en la misma fila y tampoco dentro de la misma columan que son entegadas como argumentos de la funcion
            {
                m2[fil][col] = m1[i][j]; // y los guardamo dentro de nuestra matriz auxiliar
                col++;
                if (col > n)
                {
                    fil++;
                    col = 0;
                }
            }
        }
    }

    return (pow(-1, fila + columna) * Determinante(n - 1, m2)); // finalmente devolvemos el valor de la pontencia de -1 correpondiente a la posicion del numero actual por el determeninate de la matriz generada que es de orden n -1
}
