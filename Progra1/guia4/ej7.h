/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba la función int caracteresComunes(char* cadena1, char* cadena2) y devuelva el número de caracteres 
comunes que tienen la cadena1 y la cadena2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caracteresComunes(char *cadena1, char *cadena2) // definicion de la funcion
{
    int cont = 0;                                 // definimos nuestro contador de caracteres en comun
    for (int i = 0; i < strlen(cadena1); i++)     // por cada caracter en la cadena 1
        for (int j = 0; j < strlen(cadena2); j++) // buscamos dentre de la cadena 2
            if (*(cadena1 + i) == *(cadena2 + i)) // un caracter que sea igual
            {
                cont++; // si se encuentra uno se suma una al contador
                break;  // y se pasa al siguiente caracter de la cadena 1
            }

    return cont; // finalmente devolvemos la cantidad de caracteres que tienen en comun ambas cadenas
}
