/* 

Autor: Tomas Bravo.
Solucion Propia.

Problema 11:
link a los problemas:
https://udec.instructure.com/courses/765/quizzes/34561/take
*/
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int orden, dif, dis; // declaramos la variable que contendra la el orden de nuestra matriz original y nuestras variable auxiliares

    do                  // pedimos el orden al usuario y verificamos que no sea un numero menor o igual a cero en caso contrario e le pedira que ingrese otro numero
    {
        printf("Cual es el orden de la matriz cuadrada que sera ingresada: "); 
        scanf("%d", &orden);
    } while (orden < 0);

    int original[orden][orden], distancia[orden][orden]; // declaramos la mtriz original y la matriz distancia ambas con orden filas y columnas

    printf("Ingrese la matriz %d x %d:\n", orden, orden);

    for (int i = 0; i < orden; i++)         // por cada fila  de la matriz original 
        for (int j = 0; j < orden; j++)     // por cada columna de la matriz original
        {

/* Si quiere ver en que posicion de la matriz ira cada numero que entrega cada numero descomentar la linea 34 */

            //printf("ingrese el valor %d de la fila %d de su matriz: ", j + 1, i + 1);
            scanf("%d", &original[i][j]);   // le pedimos al usuario que ingrese los numeros de cada posicion en la matriz
        }

    for (int i = orden - 1; i >= 0; --i)     // por cada fila de la matriz original
    {
        for (int j = orden - 1; j >= 0; --j) // por cada columna de la matriz original
        {
            if (i == 0 && j == 0)       // dependiendo en que posicion este el numero
            {
                dif = abs(original[i][j] - original[0][1]); // inicializamos la menor diferencia 
                dis = i + abs(j - 1);                       // y la distancia a la que estan los numeros con la menor diferencia
            }
            else
            {
                dif = abs(original[i][j] - original[0][0]); 
                dis = i + j;
            }

            for (int r = orden - 1; r >= 0; --r)        //recorremos las filas de la matriz original desde la ultima fila a la primera
            {
                for (int t = orden - 1; t >= 0; --t)    //recorremos la columnas de la matriz original desde la ultima columna hasta la primera
                {
                    
                    if (i != r || j != t)     //mientras no estemos en la misma posicion de nuestro numero actual en los dos primeros bucles for
                    {
                        int resta = original[i][j] - original[r][t];    // definimos resta que es la diferencia entre nuestro numero actual que esta en la posicion (i,j) y el numero es la posicion (t,r)
                        if (resta < 0)
                        {
                            resta *= -1;
                        }

                        if (resta <= dif)       //si el valor de resta en menor o igual a nuestra dif inicial
                        {
                           if (resta == dif)   //primero chequeamos si con iguales
                            {
                               if (abs(r-i) + abs(t - j) <= dis) // de serlo chequeamos cual de las distancias entre los valores que tienen esta diferencia igual a nuestro valor actual es la menor
                               {
                                    dis = abs(r-i) + abs(t - j); //guardamos en la variable dis la menor distancia
                               }
                            }
                            else  // en el caso de que no sea igual la diferencia pero sr menor
                            {
                                dif = resta;        // cambiamos el valor de la menor diferencia econtrada
                                dis = abs(r-i) + abs(t - j);        // y la distancia a la que esta el numero en la matriz original con la que tiene esta diferencia minima
                            }
                            
                        }
                    }
                }
            }

            distancia[i][j] = dis;      // en la misma piscision de nuestro valor actual en la matriz distancia colocamos la distancia que tiene con el numero con el que tiene la menor diferencia 
        }
    }

    printf("La matriz distancias de la matriz entregada es:\n");

    for (int i = 0; i < orden; i++)  // luego imprimimos la matriz distancia en la pantalla.
    {
        for (int j = 0; j < orden; j++)
        {
            printf("\t%d\t", distancia[i][j]);
        }
        printf("\n");
    }

    return 0;
}   