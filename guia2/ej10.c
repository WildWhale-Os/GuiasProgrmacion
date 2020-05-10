/* 


Escribe un programa que pida 16 números enteros, los almacene 
en una matriz de 4×4 y calcule el determinante de la matriz

*/

#include <stdio.h>

int Determinate(int matriz[][4], int orden);
int DetSubMatriz(int matriz[][4], int orden, int fila, int columna);

int main()
{
    int orden = 4;
    int matriz[orden][orden]; // declaracion de una matriz de 4x4

    for (int i = 0; i < 4; i++)     // itraciones por cada fila de la matriz
        for (int j = 0; j < 4; j++) //iteraciones por cada valor de cada fila de la matriz
        {
            printf("Ingrese el valor %d de la %d fila de la matriz a la que desea sacar su Determinante: ", j + 1, i + 1);
            scanf("%d", &matriz[i][j]);
        }
    
    printf("El determinante de la matriz entregade es: %d\n",Determinate(matriz,orden));

    return 0;
}

int Determinate(int matriz[][4], int orden)
{
    int det = 0;
    if (orden == 1)
        det = matriz[0][0];
    else
        for (int i = 0; i < orden; i++)
            det += matriz[0][i] * DetSubMatriz(matriz, orden, 0, i);

    return det;
}

int DetSubMatriz(int matriz[][4], int orden, int fila, int columna)
{
    int newOrden = orden - 1, x = 0, y = 0, negpos = 1;
    int subMatriz[newOrden][newOrden];

    for (int i = 0; i < orden; i++)
        for (int j = 0; j < orden; j++)
            if (i != fila && j != columna)
            {
                subMatriz[x][y] = matriz[i][j];
                y++;
                if (y >= newOrden)
                {
                    x++;
                    y = 0;
                }
            }
    for (int i = 0; i < fila+columna; i++)
        negpos *= -1;
    
    return negpos * Determinate(subMatriz,newOrden);
}