/*

Autor: Tomas Bravo
Solucion propia.

Problema 3:
Escribe un programa que pida un número entero n, a continuación, 
pida ingresar n números enteros y luego imprima: el menor, el mayor, 
el promedio (entero) y la mediana. Valide que n sea un número mayor a cero.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int mayor;
    int menor;
    int media = 0;
    int mediana = 0;

    do
    {
        printf("Digite un numero entero mayor a 0: "); // peticion de la dantidad e numeros que se usaran para hacer calculos, que sera la longitud del arreglo.
        scanf("%d", &n);

    } while (n <= 0); // SI el numero entregado previamente no es mayor que sero se le pedira al usuario un nuevo numero hasta que el numero que ingrese sea mayor a cero.

    int numeros[n]; // Declaracion del arreglo con la cantidad de elementos que el usuaio ingreso

    printf("A continuacion se le pediran %d numeros,y le diremos cual es el mayor y el menor de ellos, tambien su media y mediana\n", n);

    // Peticionde numeros al usuario para realizar operaciones
    for (int i = 0; i < n; i++)
    {
        printf("%d) Ingrese un numero: ", i + 1);
        scanf("%d", &numeros[i]);
        media += numeros[i]; // se suman los valores que el usuaria va entregando para luego / por la cantidad de dato n
    }
    // ordenar array de menor a mayor
    for (int i = 0; i < n; i++)
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
    // Calculo de la mediana
    if (n % 2 == 0) // si el numero de elementos del arreglos es par ,la mediana de los datos es el promedio de los dos valores centrales del conjunto de datos
        mediana = (numeros[(n / 2) - 1] + numeros[(n / 2)]) / 2;
    else // si es un numero impar de datos la mediana sera el numero en la posicion central entre 0 y n-1
        mediana = numeros[n / 2];

    // como el arreglo esta oordenado de menor a mayor, el primer dato del arreglo es el menor y el ultimo es el mayor.
    mayor = numeros[n - 1]; // ultimo valor del arreglo
    menor = numeros[0];     // primer valor del arreglo

    printf("El mayor de los numeros entregados es: %d\nEl menor de los numero entregados es: %d\n", mayor, menor);
    printf("El promedio de los numeros entregados es: %d\nLa mediana de los numero entregados es: %d\n", media / n, mediana);
    /*  for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            printf(" %d) %d\n", i, numeros[i]);
        else
            printf(" %d) %d -", i, numeros[i]);
    } */

    return 0;
}