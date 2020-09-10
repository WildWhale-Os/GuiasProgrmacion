/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que pida un caracter e imprima mayuscula, minuscula, numero u otro según sea el caso.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char caracter;                              // declaramos l avriable que contendra el caracter que nos sera entregado por teclado
    printf("Ingrese un caracter cualquiera: "); // pedimos el caracter
    scanf("%c", &caracter);                     //leemos y guardamos el caracter en la variable definida previamente

    if (caracter >= 'A' && caracter <= 'Z')                                                          // verificamos que el caracter entegado sea una letra mayuscula
        printf("El caracter entregado es una letra mayuscula.\n");                                   // si es una letra mayuscula imrpimimos que el caracter es una letra mayuscula
    else if (caracter >= 'a' && caracter <= 'z')                                                     // si no es mayuscula verificamos i es minuscula
        printf("El caracter entregado es una letra minuscula.\n");                                   // de ser asi imrpimimos que el caracter entregado es una minuscula
    else if (caracter >= '0' && caracter <= '9')                                                     // si no es minuscula verificamos que sea un numero
        printf("El caracter enrtegado es un numero\n");                                              // si es un numero imprimiremos que el caracter entregado es un numero
    else                                                                                             // si no es ni una letra de ningun tipo ni tampoco un numero
        printf("El caracter entregado es otro tipo de caracter (no es una letra, ni un numero).\n"); // imprimimiremos que el caracter entergado es otro tipo de caracter

    return 0;
}