/*
Autor: Tomas Bravo
Solucion Propia.

timus_ID = TomasBravo
Judge_ID = 295450ZH

Timus 1313. Some Words about Sport


*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int orden;                      // declaraccio variable que contendra el alto y ancho de nuestra matriz de datos
    scanf("%d", &orden);            // se le pide al usuario que ingrese que orden tendra la matriz n x n
    if (orden >= 1 && orden <= 100) // el orden debe vivir en 1 <= orden <= 100
    {
        int matriz[orden][orden], matrizLinea[orden * orden]; // se declara la matriz donde se guardaran los datos y el array donde iran los datos en el orden dado en el enunicado
        int pos = 0, suma = 0, good = 1;                      // declaracion de variables auxiliares

        for (int i = 0; i < orden; i++)     // por cada fila de la matriz
            for (int j = 0; j < orden; j++) // por cada valor j de la fila i de matriz
            {
                scanf("%d", &matriz[i][j]);                 // se leeran y guardaron los numeros entregados por teclado
                if (matriz[i][j] < 0 || matriz[i][j] > 100) // si el numero entregado no vive en 0 < matriz[i][j] <= 100, el programa se termina
                {
                    good = 0;
                }
            }

        if (good == 1) // todos los valores entregados viven en el intervalo dado
        {
            while (suma <= (orden - 1) * 2) // mientras que la suma i+j se menor a (n -1) * 2 haremos
            {
                for (int i = orden - 1; i >= 0; i--)     // pasamos desde la ultima fila
                    for (int j = orden - 1; j >= 0; j--) // desde el ultimo elemento hasta el primer elemte de cada fila
                        if (i + j == suma)               // buscando las posiciones donde la suma de los componentes sea igual a suma
                        {
                            matrizLinea[pos] = matriz[i][j]; // agregamos el valor de aquella posicion de matriz a el array definida mas arriba en la pos actual en la que estamos en el array
                            pos++;                           // avanzamos una pos en el array
                        }
                suma++; // le sumamos uno a el valor de suma que para que busque la siguiente diagonal
            }

            for (int i = 0; i < orden * orden; i++) // imprimis el array en pantalla
            {
                printf("%d ", matrizLinea[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
