/* 

Autor: Tomas Bravo

Escribe un programa que pida un número entero n, a continuación, pida ingresar 
n números enteros y luego los imprima ordenados como se especifica a continuación. 
Primero, deberán aparecer todos los números pares, ordenados de menor a mayor y 
luego los impares ordenados de mayor a menor.

*/
#include <stdio.h>

int main()
{
    int cant;
    int nPares = 0;
    int nImpares = 0;

    do // verificacion de que el numero sea mayor que 0 para que no se procesen 0 datos o una cantiada de datos negativa
    {
        printf("Cuantos numeros va a ingresar para ser procesados, si ingresa 0 no se procesara nada: ");
        scanf("%d", &cant);
    } while (cant < 0);

    if (cant > 0)
    {
        int numeros[cant]; // declaracion del array que contendara todos los datos que seran procesados

        for (int i = 0; i < cant; i++) // Se le piden los valores a procesar al usuario
        {
            printf("%d) Por favor un numero para procesar: ", i + 1);
            scanf("%d", &numeros[i]); // se guardan los datos en el array
            if (numeros[i] % 2 == 0)
                nPares += 1;
            else
                nImpares += 1;
        }

        //declaracion de los arreglos que contendran a los numero pares e impares respectivamente del conjunto entregado
        int pares[nPares];
        int impares[nImpares];
        // odenamos el conunto de numeros entregados.
        for (int i = 0; i < cant; i++)
        {
            int posicionActual = i;
            int numeroActual = numeros[i];
            while (posicionActual > 0 && numeros[posicionActual - 1] > numeroActual)
            {
                numeros[posicionActual] = numeros[posicionActual - 1];
                posicionActual--;
            }
            numeros[posicionActual] = numeroActual;
        }

        int posPares = 0;
        int posImpares = 0;
        for (int i = 0; i < cant; i++)
        {

            if (numeros[i] % 2 == 0)
            {
                pares[posPares] = numeros[i];
                posPares++;
            }
            else
            {
                impares[posImpares] = numeros[i];
                posImpares++;
            }
        }
        // imprimir el array ordenada para confirmacion
        /*  for (int i = 0; i < cant; i++)
    {
        if (i == 0)
            printf("%d", numeros[i]);
        else
            printf(" - %d", numeros[i]);
    }
    printf("\n"); */
        // imprimiendo las pares odernados de forma ascendente
        printf("Los numeros pares ingresados ordenados de forma ascendete: ");
        for (int i = 0; i < nPares; i++)
        {
            if (i == 0)
                printf("%d", pares[i]);
            else
                printf(" - %d", pares[i]);
        }
        // imprimir impares ordenados de forma descendente
        printf("\nLos numeros impares ingresados ordenados de forma descendente: ");
        for (int i = nImpares - 1; i >= 0; i--)
        {
            if (i == nImpares - 1)
                printf("%d", impares[i]);
            else
                printf(" - %d", impares[i]);
        }
        printf("\n");
    }

    return 0;
}