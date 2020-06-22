/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que redondee un número decimal, recibido por 
entrada, al entero correspondiente. Entregue el resultado como un número entero.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;                                                                              // declaramos una variable float donde guardaremos el numero que tendremos que aproximar
    printf("Ingrese un numero con decimas de unidad a ser redondeado: ");                   // pedimos el numero
    scanf("%f", &num);                                                                      // leemos y guardamoes el numero
    if (num - (int)num >= 0.5000000)                                                        // verificamos que el numero entregado menos el entero del mismo numero sea mayor o igual a 0.5
        printf("EL numero redondeado al entero mas cercano es igual a %d\n", (int)num + 1); // de ser asi imprimimos el entero del numero entregado mas 1
    printf("EL numero redondeado al entero mas cercano es igual a %d\n", (int)num);         // caso contrario imprimimos el entero del numero

    return 0;
}