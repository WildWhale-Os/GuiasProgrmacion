/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que lea un número de punto flotante e imprima por 
pantalla la suma de todos los dígitos que lo componen.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000]; // delcaramos el arreglo donde guardaremos el numero con punto flotante que se nos entregara
    int suma = 0;   // variable donde sumaremos todos los numeros que posea el numero con punto flotante que se nos entregara

    printf("Ingrese un numero con putno flotante: "); // pedimos el numero con punto flotante
    scanf("%s", str);                                 // y lo guardamos en el arreglo que declaramos anterioemente

    for (int i = 0; i < strlen(str); i++) // por cada caracter del arreglo
    {
        if (str[i] >= '0' && str[i] <= '9') // si es un numero
        {
            suma += str[i] - '0'; // lo cambiamos a su forma intera y se lo sumamos a la variable suma
        }
    }

    printf("la suma de todos los digitos que formaban el numero entregado es igual a %d.\n", suma); // imprimimos el resultado de todos los numero entero que componian el numero con punto flotante

    return 0;
}