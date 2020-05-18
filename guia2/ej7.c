/* 

Autor: Tomas Bravo 
Con ayuda de Sebastian Aguila.

Problema 7:
Escribe un programa que pida un numero entero n, lea n numeros enteros 
y luego imprima todas las posibles permutaciones de 3 de esos numeros.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArray; // variable que contendra el largo de nuestro array
    do
    {
        printf("Digite un numero entero mayor a 0: ");
        scanf("%d", &sizeArray); // se lee el numero ingresa por teclado y se guarda en nuestra variable n
    } while (sizeArray < 0); // si n es menor que 0 se pedira que ingrese otro numero

    int numeros[sizeArray]; // declaramos nuestro array de largo n

    for (int i = 0; i < sizeArray; i++) // llenamos nuestro array con datos ingresador por teclado
    {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Las combinaciones de 3 numeros que se pueden hacer con los %d numeros entregados son: \n",sizeArray);

    int contador = 0; // declaramos un contador para llevar la cuenta de cuantas permutaciones hemos hecho
    switch (sizeArray) // dependiendiendo del largo de nuestro array haremos
    {
        case 0:
            printf("No se puedes hacer combinaciones con 0 elementos\n");
            break;
        case 1: // si es de largo 1 solo imprimiremos el primer valor del array
            printf("%d\n", numeros[0]);
            break;
        case 2: // si es dos solo imprimiremos las 2 permutaciones que tienen los numeros en nuestro arreglo 
            for (int i = 0; i < sizeArray; i++)
                for (int j = 0; j < sizeArray; j++)
                    if (j != i)
                        printf("%d  %d\n", numeros[i], numeros[j]);

            break;
        default: // en caso de tener un largo mayor o igual a tres
            for (int i = 0; i < sizeArray; i++) // por cada elemento del array
                for (int j = 0; j < sizeArray; j++) // recorremos todos los elemtos del array
                    if (j != i)// mientras que no estemos en la misma posicion en el array
                        for (int p = 0; p < sizeArray; p++) // recorremos el array una tercer vez
                            if (p != j && p != i) // y mientras estas tres veces que recorremos cada valor no se encuentren en la misma posicion del array
                            {
                                contador++; // aumentaremos en contador dando cuenta de una permutacion hecha
                                printf("%d) %d  %d  %d\n", contador,numeros[i], numeros[j], numeros[p]); // imprimimos la permutacion
                            }
            break;
    }

   
    return 0;
}

