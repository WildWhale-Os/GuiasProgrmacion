/* 
Autor: Tomas Bravo
Solucion propia.

Problema 2:
Escribe un programa que pida un número entero n y a continuacion imprima 
las n primeras potencias de dos. El programa debe validar la entrada cuidando 
que el valor ingresado no sea negativo.
*/
#include <stdio.h>

int main()
{
    int numero;
    int resultado = 1; // se declaran la variable "numero" donde se almacenara el numero ingresado por teclado

    do //nos aseguramos de que el numero entregado de sea negativo
    {
        printf("Introdusca un numero mayor o igual a 0: ");
        scanf("%d", &numero); // si el numero entrego al inicio del programa es negativo se le pedira al usuario que ingrese otro
    } while (numero < 0);

    printf("Las primera %d potencias de 2 son: \n",numero );

    for(int i=0; i < numero; i++)
    {
        // si es que el numero es mayor a cero
        printf("%d) %d\n", i + 1, resultado); // se imprimaran las primera "numero = n" potencias de 2, partiendo con 2^0
        resultado *= 2;
        
    }
    return 0;
}