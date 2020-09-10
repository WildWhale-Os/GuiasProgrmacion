/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que pida un número entero (de 4 Bytes) y luego imprima 
tanto la representación entera como el código ASCII correspondientes a cada 
uno de los bytes que componen el número ingresado.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int num;                     // creamos una variable para guardar un numero entero sin signo
    printf("Ingrese un numero entero: "); // pedimos un numero cualquiera
    scanf("%u", &num);                    // y lo guardamos como un numero sin signo
    unsigned int bytes[4];                // declaramos el arrego que guardara todos los bytes que conforman a nuestro numero entero
    bytes[0] = num >> 24;                 // aislamos el primer byte de izqueda a deracha
    bytes[1] = (num << 8) >> 24;          // aislamos el segundo byte de izquerda a derecha
    bytes[2] = (num << 16) >> 24;         // aislamos el tercer byte de izquerda a derecha
    bytes[3] = (num << 24) >> 24;         // aislamos el cuarto byte de izquerda a derecha

    for (int i = 0; i < 4; i++) // por cada byte que conforma nuestro numero entero
    {
        printf("La representacion entera del byte numero %d del entero ingresado es %u\n", i + 1, bytes[i]); // impirmirmos si representacion como entero sin signo.
        printf("---------------------------------------------------------------------------------------\n");
    }

    return 0;
}