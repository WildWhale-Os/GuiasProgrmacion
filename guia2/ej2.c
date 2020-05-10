/* 
Autor: Tomas Bravo

Escribe un programa que pida un número entero n y a continuación imprima 
las n primeras potencias de dos. El programa debe validar la entrada cuidando 
que el valor ingresado no sea negativo.
*/
#include <stdio.h>

int main()
{
    int numero, control = 0;
    int resultado = 1; // se declaran la variable "numero" donde se almacenara el numero ingresado por teclado

    do //nos aseguramos de que el numero entregado de sea negativo
    {
        printf("Introdusca un numero mayor o igual a 0: ");
        scanf("%d", &numero); // si el numero entrego al inicio del programa es negativo se le pedira al usuario que ingrese otro
    } while (numero < 0);

    for(int i=0; i < numero; i++)
    {
        // si es que el numero es mayor a cero
        printf("%d) %d\n", control + 1, resultado); // se imprimaran las primera "numero = n" potencias de 2, partiendo con 2^0
        resultado *= 2;
        control++; // se aumenta la variable de control para que el bucle se ejecute "numero" veces
    }
    return 0;
}