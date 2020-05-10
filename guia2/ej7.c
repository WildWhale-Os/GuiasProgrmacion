/* 

Autor: Tomas Bravo, con ayuda de Sebastian Aguila.

Escribe un programa que pida un número entero n, lea n números enteros 
y luego imprima todas las posibles permutaciones de 3 de esos números.

*/

#include <stdio.h>
#include <stdlib.h>


void PermutarArreglo(int array[], int sizeArray);

int main()
{
    int n;
    srand(time(NULL));
    do
    {
        printf("Digite un numero entero mayor a 0: ");
        scanf("%d", &n);
    } while (n < 0);

    int numeros[n];

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    PermutarArreglo(numeros, n);

    return 0;
}

void PermutarArreglo(int array[], int sizeArray)
{
    int contador = 0;
    switch (sizeArray)
    {
    case 1:
        printf("%d\n", array[0]);
        break;
    case 2:
        for (int i = 0; i < sizeArray; i++)
            for (int j = 0; j < sizeArray; j++)
                if (j != i)
                    printf("%d  %d\n", array[i], array[j]);

        break;
    default:
        for (int i = 0; i < sizeArray; i++)
            for (int j = 0; j < sizeArray; j++)
                if (j != i)
                    for (int p = 0; p < sizeArray; p++)
                        if (p != j && p != i)
                        {
                            contador++;
                            printf("%d) %d  %d  %d\n", contador,array[i], array[j], array[p]);
                        }
        break;
    }
}
