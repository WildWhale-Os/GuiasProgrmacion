/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mayor(int *v, int n)
{  
    if (n - 1 >= 0) // mientras estemos dentro de los indices del arreglo
    {
        int aux = mayorNumero(v, n - 1); // ejecutaremos recursivamente hasta que nos salgamos de arreglo, de esta forma definimos la cola
        if (v[n - 1] > aux)              // ahora comparamos el valor actual del arrglo con el mayor numero de la cola encontrado
            return v[n - 1];          // si es mayor el numero actual retornamos ese valor
        else
            return aux; // si no es mayor devolvemos el valor mas grande de la cola
    }
    return INT_MIN; // de forma Predeterminada devolvemos el valor mas chico que puede almacenar una variable entera
}