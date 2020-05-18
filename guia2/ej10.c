/* 

Autor: Tomas Bravo.
Solucion Propia.

Problema 10:
Escribe un programa que pida 16 números enteros, los almacene 
en una matriz de 4×4 y calcule el determinante de la matriz

*/

#include <stdio.h>


int main()
{
    int matriz[4][4], matrizAux3[3][3], matrizAux2[2][2]; // declaracion de una matrizes necesarias para resolver el problema
    int det = 0;
    printf("Ingrese los elementos de la matriz de 4 x 4:\n");
    for (int i = 0; i < 4; i++)     // itraciones por cada fila de la matriz
        for (int j = 0; j < 4; j++) //iteraciones por cada valor de cada fila de la matriz
        {
    /* Si quiere saber con certeza en que posicion de la matriz esta ingresando el valor descomente la linea 23 */
            //printf("Ingrese el valor %d de la %d fila de la matriz a la que desea sacar su Determinante: ", j + 1, i + 1);
            scanf("%d", &matriz[i][j]);
        }
    for (int i = 0; i < 4; ++i) // recorrer la primera fila de la matriz
    {
    
        int orden = 4, filaAux= 0, valor4x4 = matriz[0][i],colAux = 0, negOPosM4, negOPosM3; //declaramos variables temporales para ayudarnos

        for (int j = 0; j < orden; ++j) // recorrer cada fila de la matriz 4x4
        {
            for (int r = 0; r < orden; ++r) // recorrer cada columna de la matriz 4x4
            {
                if(j != 0 && r != i) // si el numero en el que estamos no esta ni en la misma fila ni en la misma columna que valor4x4 
                {
                    matrizAux3[filaAux][colAux] = matriz[j][r]; // lo agregamos a la submatriz de 3x3 que es cofactor de nuestro valor4x4
                    colAux++;
                    if(colAux >= orden - 1)
                    {
                        filaAux++;
                        colAux = 0;
                    }
                }
            }
        }

        if ((0 + i)% 2 == 0) // obtenemos la potencia de -1 que nos pide la formula de el determiante de un matriz 
            negOPosM4 = 1;
        else
            negOPosM4 = -1;

        for (int j = 0; j < orden - 1; ++j) // recorremos la primera fila de la matriz de 3x3
        {
            int valor3x3 = matrizAux3[0][j];
            filaAux = 0;
            colAux = 0;

            for (int t = 0; t < orden - 1; ++t) // recorrer cada fila de la matriz 3x3
            {
                for (int r = 0; r < orden - 1; ++r) // recorrer cada columna de la matriz 3x3
                {
                    if(t != 0 && r != j) // si el numero en el que estamos parados no esta ni en la misma fila ni en la misma columna que valor3x3
                    {
                        matrizAux2[filaAux][colAux] = matrizAux3[t][r]; // lo agregamos a la matriz de 2x2 de que es cofactor de valor3x3
                        colAux++;
                        if(colAux >= orden - 2)
                        {
                            filaAux++;
                            colAux = 0;
                        }
                    }
                }
            }
            if ((0 + j)%2 == 0) // objtenemos la potencia de -1 que nos pide la formula del determinate
                negOPosM3 = 1;
            else
                negOPosM3 = -1;

            int det2x2 = (matrizAux2[0][0] * matrizAux2[1][1]) - (matrizAux2[0][1] * matrizAux2[1][0]); // calculamos el determinate de una matriz de 2x2
            // en cada valor de la primera fila de la matriz de 4x4 y de 3x3 sumamos los valores correspondientes a la 
            det += valor4x4 * negOPosM4 * ( valor3x3 * negOPosM3 * det2x2); 
        }
    }

    printf("El determinante de la matriz entregada es: %d\n",det); // imprimir el determinante de la matriz dada

    return 0;
}