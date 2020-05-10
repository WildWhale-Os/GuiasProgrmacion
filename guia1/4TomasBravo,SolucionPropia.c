/*
Problema:
Escribe un programa que pida dos números, los almacene en dos variables distintas y 
los intercambie en caso de que ambos sean negativos. La operación de intercambiar dos 
números (conocida como operación “swap”) se refiere a intercambiar el contenido de dos
direcciones de memoria.
*/
#include <stdio.h>

void Swap(int numero1, int numero2)
/* Operacion Swap, necesita dos variables de tipo enteras a las cuales 
cambiara el valor de cada una de ellas por el valor de la otra*/
{
    int auxiliar = 0; // Declaracion de una variable que no ayudara a cambiar los valores de las variables

    printf("Haciendo el intercambio...\n");

    auxiliar = numero1; // Cambia el valor de la variable auxiliar por el valor de numero1
    numero1 = numero2; // cambia el valor de la variable numero1 por el valor de numero2
    numero2 = auxiliar; // cambia el valor de la variable numero2 por el valor de auxiliar

    printf("El valor del primer numero es %i\nEl valor del segundo numero es %i\n", numero1, numero2);
}

int main(void)
{
    
    int numero1, numero2, auxiliar = 0;
    printf("Ingrese 2 numeros: ");
    scanf("%i %i", &numero1, &numero2); // Lectura de datos entrgados por teclado

    printf("El valor del primer numero es %i \nEl valor del segundo numero es %i\n", numero1, numero2);

    if (numero1 < 0 && numero2 < 0) // ambos numeros entregados por teclado son negativos.
    {
        Swap(numero1, numero2);// se ejecutara la oprecaion swap definida mas arriba.
    }
    else // caso contrario
    {
        printf("El orden de los numeros no a cambiado.\n"); //solo imprimira "El orden de los numeros no a cambiado."
    }

    return 0;
}

