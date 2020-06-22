/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que lea dos líneas de texto e imprima todas las 
palabras (sin repetir) que se encuentran en las dos líneas ingresadas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Funciones
void imprimirPalabras(char *cadena);

int main()
{
    char cad1[1000], cad2[1000]; // definimos arreglo de caracteres donde se almacenara cada linea de texto ingresada

    printf("Ingrese dos lineas de texto:\n");                   // pedimos las dos lineas de texto
    scanf("%[^\n]s", cad1);                                     // leemos la primero linea de texto y la guardamos en cad1
    getchar();                                                  // limpiamos el buffer del teclado
    scanf("%[^\n]s", cad2);                                     // leemos la segunda linea de texto y la guardamos en cad2
    getchar();                                                  // limpiamos el buffer del teclado
    printf("----------------------------------------------\n"); // algunos adornos
    printf("Todas las palabra que fueras escritas son:\n");
    printf("----------------------------------------------\n");

    imprimirPalabras(cad1); // imprimimos las palabras que componen a toda la linea de texto
    imprimirPalabras(cad2); // imprimimos todas las palabras que componen la segunda linea de texto

    return 0;
}

void imprimirPalabras(char *cadena) // esta funcion imprime todas las palabras que componen una cadena de texto en forma de lista
{
    for (int i = 0; i < strlen(cadena); i++) // por cada caracter en nuestra cadena de caracteres
    {
        if (cadena[i] != ' ')        // si el caracter no es un esapcio
            printf("%c", cadena[i]); // imprimimos el caracter
        else                         // si el caracter es un espacion
            printf("\n");            // imprimimos un salto de linea
        if (i == strlen(cadena) - 1) // si estamos en el ultimo elemento del arreglo
            printf("\n");            // imprimimos un salto de linea
    }
}