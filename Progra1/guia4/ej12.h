/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba una función int buscar(int n, double* v, double e) que recibe un arreglo 
de números de coma flotante de doble precisión v, su tamaño n y un elemento
a buscar e. La función deberá devolver la posición del elemento en el arreglo, 
en caso de estar contenido, o −1 en caso contrario. Recuerde que para la comparación 
de números de punto flotante, se debe utilizar un margen de error, por posibles errores 
de precisión. Utilice la constante 1 × 10 ^−6 como constante para error de precisión. 
Implemente esta función sin utilizar el operador [ ].

*/
#include <stdio.h>
#include <math.h>

int Buscar(int n, double *v, double e) // definicion de la funcion que buscar un numero dentro de un arreglo de largo n de numeros
{
    for (int i = 0; i < n; i++)               // recorremos todos los numeros en arreglo
        if (fabs(*(v + i) - e) < pow(10, -6)) // si la resta uan de los numero y el numero e que buscamos es menor a 0,000001
            return i;                         // significa que son iguales entonces devolvemos su posicion

    return -1; // si ningun numero del arreglo cumple con la condicion significa que el numero no esta contenido en el arreglo entonces devolvemos -1
}