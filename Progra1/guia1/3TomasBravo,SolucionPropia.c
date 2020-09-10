/*
Problema:
Escribe un programa que pida tres numeros e imprima:
"Cumple invariante" si el primero, sumado con el segundo, es menor
al cuadrado del tercero dividido por el primero.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Lectura de datos entrgados por teclado
    int numero1, numero2, numero3, resultado1 = 0, resultado2 = 0;
    printf("Ingrese 3 numeros: ");
    scanf("%i %i %i", &numero1, &numero2, &numero3);

    resultado1 = numero1 + numero2; // valor de la suma de los dos primeros numeros entregados por teclado.
    resultado2 = (numero3 * numero3) / numero1;
    // valor de la division del tercer numero entregado por teclado al cuadrado dividido por el primero numero entregado.

    if (resultado1 < resultado2) 
    {
        /*si valor de la suma de numero1 y numero 2 es menor a la division
        de numero3 al cuadrado dividido por numero1*/

        printf("Cumple invariante \n"); // imprime en pantalla "Cumple invariante"
    }
    else // caso contrario
    {
        printf("No cumple invariante \n"); // imprime en pantalla "No Cumple invariante"
    }

    return 0;
}