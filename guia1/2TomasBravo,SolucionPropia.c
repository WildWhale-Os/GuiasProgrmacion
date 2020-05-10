/*
Problema:
escribe un programa que pida dos numeros enteros e imprima 
el doble del menor de ellos.
*/

#include <stdio.h>

int main(void)
{
   
    int numero1, numero2; // declaraciones de variables
    printf("Digite 2 numeros: ");
    scanf("%i %i", &numero1, &numero2); //se le asignan valores a las variables declaradas por medio de teclado.

    if (numero2 >= numero1) // si valor numero2 es mayor o igual que valor de numero1
    {
      
        printf("El doble del numero menor es %i \n", 2 * numero1);
        // se imprimira en pantalla el doble del valor de numero1
    }
    else // si valor de numero1 es mayor que el valor de numero2
    {
        
        printf("El doble del numero menor es %i \n", 2 * numero2); 
        // se imprimira en pantalla el doble del valor de numero2
    }

    return 0;
}