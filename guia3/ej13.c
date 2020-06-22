/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escribe un programa que lea dos líneas de texto, a continuación, 
el programa deberá concatenar el resultado de invertir cada una 
de las líneas, para finalmente imprimir las vocales del resultado 
en el orden final.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones
void InvertirCadena(char *cadena);
void ImprimirVocales(char *cadena);

int main()
{
    char text1[1000], text2[1000];          // declaramos los arreglo de caracteres donde vamos a guardar las dos lineas de texto que van a ser ingresadas
    printf("Ingrese dos lineas de texto: \n"); // pedimos las dos lineas de texto
    scanf("%[^\n]s", text1);                   // leemos la primera linea de texto y la gardamos en text1
    getchar();                                 // limpiamos el buffer del teclado
    scanf("%[^\n]s", text2);                   // leemos la segunda linea de texto y la gardamos en text2
    getchar();                                 // limpiamos el buffer del teclado

    // invertimos las las lineas de texto entregadas y imprimimos las vocales
    InvertirCadena(text1);
    InvertirCadena(text2);

    printf("\n");
    return 0;
}

void InvertirCadena(char *cadena)
{
    for (int iz = 0, der = strlen(cadena) - 1; iz < der; ++iz, --der) // desde el inicio de la cadena y desde el final de la cadena
    {
        // hacemos un swap de los elemtos que estan a los extrmos del arreglo misntras que avanzamos hacia el centro de la cadena
        char aux = cadena[der];
        cadena[der] = cadena[iz];
        cadena[iz] = aux;
    }
    ImprimirVocales(cadena);
}

void ImprimirVocales(char *cadena)
{
    for (int i = 0; i < strlen(cadena); ++i) // recorremos el arreglo
    {
        switch (cadena[i]) // si la el caracter en la posicion actual del arreglo
        {
            // es una vocal mayuscula o minuscula
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%c", cadena[i]); // imprime el caracter
            break;
        }
    }
}