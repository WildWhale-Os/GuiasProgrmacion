/*
Autor: Tomas Bravo
Tipo de Solucion: Ayuda de Sebastian Aguila.
timus_ID = TomasBravo
Judge_ID = 295450ZH
https://acm.timus.ru/problem.aspx?spacez=1&num=1209
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num; // variable donde guardaremos el numero de posiciones que nos entregaran

    scanf("%d", &num);            // leemos y guardamos cuantas posiciones nos entregaran
    if (num >= 1 && num <= 65535) // si nos van a entregar como minimo 1 posicion y maximo 65535 posiciones hacemos
    {
        double pos, raiz;             // declaramos la variable pos que es donde guardaremos las posiciones cada vez que son entregadas
        int sqrti;                    // variable para comparar un entero y un double
        for (int i = 0; i < num; i++) // por cada una de las posiciones que nos entregaran
        {
            scanf("%lf", &pos);                                    // leemos y guardamos la poscion entregada
            if (pos < (double)1 || pos > (double)(pow(2, 31) - 1)) // verificamos que este entre los limites entregados por el problema
            {
                break;    // si nos lo esta terminamos el bucle
                return 0; // y salimos del programa
            }
            else // si es correcto el numero ingresado
            {

                raiz = sqrt(8 * pos - 7); //calculamos esta raiz como un double , esta raiz se obtiene al igualar la suma de los primeros numeros naturales + 1 con uan posicion p aleatoria
                sqrti = raiz;             // guardamos solo el entero de la raiz
                if (raiz == sqrti)        // si las raiz es un entero
                    printf("%d ", 1);     // imprimimos un 1
                else                      // si no
                    printf("%d ", 0);     // imprimimos 0
            }
        }

        printf("\n");
    }

    return 0;
}