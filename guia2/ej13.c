/* 
Autor: Tomas Bravo 
Solucion Propia.
timus_ID = TomasBravo
Judge_ID = 295450ZH

Problema 13:
Timus 1068. Sum


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result = 0, cota; // definimas la variables

    scanf("%d", &cota);                  // pedimos hasta que numero sumaremos desde 1
    if (cota <= 10000 && cota >= -10000) // el abs(cota) debe ser menor o igual a 10000
    {
        if (cota > 0)                       // si vamos a sumar desde uno hasta un numero porsitivo
            for (int i = 1; i <= cota; i++) // solo recorremos los numeros desde el 1 hasta cota sumandolos
                result += i;

        else                                // si sumamos de 1 hasta un numero negativo
            for (int i = cota; i <= 1; i++) // partiremos sumando desde el numero entregado hasta uno.
                result += i;

        printf("%d\n", result); // imprimimos el resultado de la suma.
    }

    return 0;
}