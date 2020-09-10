/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que lea una línea de texto con el siguiente formato: 
"2xN1 3xN2", donde N1 y N2 son números, e imprima el menor entre ellos. 
Note que no hay espacios en cada una de las dos expresiones. Se exige que 
se lea la entrada como una cadena de caracteres.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// funciones usadas en el programa
int CtoI(char *cadena);
int AislarNumeros(char *cadena, int opcion);
int esNumero(char c);

int main()
{
    char cadena[32]; // declramos loa arreglos de caracteres que contendran tonta la string que se nos entregara y los numeros que aislaremos
    int n1, n2;      // variables auxiliares

    printf("Ingrese 2 numeros de las la siguiente forma (2xN1 3xN2).\nDonde N1 y N2 son los numeros que quiere ingresar: "); // pedimos que se ingrese la string con los numeros en ella
    scanf("%[^\n]", cadena);                                                                                                 //leemos y guardamos la string
    getchar();                                                                                                               // limpiamos el buffer del teclado

    n1 = AislarNumeros(cadena, 0); // llamamos a la funcion que nos aislara el primer numero
    n2 = AislarNumeros(cadena, 1); // llamamos a la funcion que nos aislara el segundo numero

    if (n1 > n2) // buscamos cual es el mayor entre los dos
        printf("El menor entre los dos numeros entregados es %d\n", n2);
    else // y imprimimos el numero menor
        printf("El menor entre los dos numeros entregados es %d\n", n1);

    return 0;
}

int esNumero(char c) // esta funcion nos devuel ve si un caracter es un numero
{
    return (c >= '0' && c <= '9');
}

int CtoI(char *cadena) // esta funcion un numero en formato de cadena de caracteres a entero
{
    int num = 0;
    for (int i = 0; i < strlen(cadena); i++) // por cada caracter en la cadena
    {
        if (cadena[i] != '0')                                                  // verificamos que no sea un caracter 0
            num += (int)(cadena[i] - '0') * pow(10, strlen(cadena) - (1 + i)); // tomamos el numero en forma de caracter y le restamos el caracter 0 para que se vuelva en su forma entera y lo multiplicamos por la potencia de 10 que corresponde dependiendo se es una unidad, decena, centena, etc.
    }
    return num; // retornamos el numero en su forma de numero entero
}

int AislarNumeros(char *cadena, int opcion)
{
    int numPos = 0, pos;
    char num[strlen(cadena)];

    if (!opcion)                   // dependiendo de que numero queramos aislar
    {                              // al querer aislar el primer numero entregado
        pos = 0;                   // empezamos desde la posicion 0 de la cadena entregada
        while (cadena[pos] != ' ') // hasta encontrar un espacio
        {
            if (esNumero(cadena[pos]) && cadena[pos + 1] != 'x') // si no encontramos con un numero que no este a la izqueda de un x
            {
                num[numPos] = cadena[pos]; // lo guardamo dentre de nuestro arreglo que contendra nuestro numero
                numPos++;                  // y avanzamos una posicion en el mismo arreglo en el que guardamos el numero
            }
            pos++; // avanzamos un lugar en la cadena madre
        }
        num[numPos] = '\0'; // finalmente agregamos al ultima posicion el caracter fin de string
    }
    else // su queremos aislar el segundo numero
    {
        for (int i = 0; i < strlen(cadena); i++) // recorremos toda la string madre
        {
            if (cadena[i] == ' ') // hasta encontrar un espacio dentro del arreglo
            {
                pos = i + 1; // guardamos la posicion siguiente
                break;       // y salimos del bucle
            }
        }

        while (cadena[pos] != '\0') // desde la posicion en la que se encuentra el espacio hasta el final de la string
        {
            if (esNumero(cadena[pos]) && cadena[pos + 1] != 'x') // buscaremos numeros que no esten a la izquerda de una x
            {
                num[numPos] = cadena[pos]; // y los guardaremos en nuestro arrglo que guarda un numero
                numPos++;                  // aumentamos la posicion de nuestro arreglo de nuestro numero final
            }
            pos++; // avanzamos uno en nuestro arreglo madre
        }
        num[numPos] = '\0'; // y el ultimo caracter en nuestro caracter del numero final sera el caracter fin de string
    }

    return CtoI(num); // retornamos el numero en si forma de entero
}