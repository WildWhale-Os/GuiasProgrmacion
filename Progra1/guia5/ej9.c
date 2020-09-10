/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
#include <stdlib.h>

int busquedaBinaria(int *v, int elem, int limInferior, int limSuperior)
{
    int retorno = -1;               // valor predeterminado a retornar es -1
    if (limInferior <= limSuperior) // ejecutaremos la funcion recursivamente mientras el limite inferior <= limite superior
    {
        if (v[limInferior] == elem)                                       // si el elemento en el limite inferior es igual al elemento buscado
            return limInferior;                                           // devolves la posicion indicada por el valor de limite inferior y termina la funcion
        retorno = busquedaBinaria(v, elem, limInferior + 1, limSuperior); // mientras estemos dentros de los limites ejecutaremos la funcion de busqueda de forma recursiva
    }
    else                // si nos salimos de los limites
        return retorno; // retornamos el valor actual de la variable retorno
}