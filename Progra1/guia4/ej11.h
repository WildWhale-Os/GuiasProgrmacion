/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba una función void estadisticos(int n, double* v, double* min, double* max que 
recibe un arreglo de números de coma flotante de doble precisión v y su tamaño n y 
calcula y almacena en los parámetros por referencia min,max,mediana,promedio,devEst 
su valor mı́nimo, el máximo, la mediana, el promedio y la desviación estándar respectivamente.

*/
#include <stdio.h>
#include <math.h>

void Swap(double *n1, double *n2); //declaracionde la funcion que cambia la posicion de dos numeros.

void Estadisticos(int n, double *v, double *min, double *max, double *mediana, double *promedio, double *devEst)
{                                   // definicion de la funcion Estadisticos
    *promedio = 0;                  // como el promedio se calcular mediante una acumulacion de valores la inicilizamos en 0
    *devEst = 0;                    // por la misma razon el valore de la desviacion estandar tambien parte en 0
    for (int i = 0; i < n - 1; i++) // por cada valor del arreglo
    {
        for (int j = i + 1; j < n; j++) // todos los numeros posteriores a el
        {
            if (v[i] > v[j])        // si posterio a el hay un numero que es menor
                Swap(&v[i], &v[j]); // cambiamos los dos numeros
        }
        *promedio += v[i]; // por cada valor en el arreglo lo sumamos a la variable promedio
    }

    *promedio /= n;                                 // al final despues de haber sumados todos los numero del arreglo dividimos la sumatorio de todos esos numero en la cantidad de numero que es n
    *min = v[0];                                    // como el arreglo esta ordenado de menor a mayor, el primer numero en el arreglo es el menor del conjunto
    *max = v[n - 1];                                // mientras que el ultimo numero en el conjunto es el mayor
    if (n % 2 == 0)                                 // para calcular la mediana tenemos que ver si el numero total de datos es par o impar y el conjunto de datos tiene que estar ordenado de forma creciente
        *mediana = (v[n / 2] + v[(n / 2) - 1]) / 2; // si la cantidad total de datos es una numero par entonces la mediana sera igual al promedio entre los dos numero centrales
    else                                            // si no es par
        *mediana = v[(n - 1) / 2];                  // la mediana sera igual al dato central del arreglo

    for (int i = 0; i < n; ++i)                  // por cada numero dentre del arreglo
        *devEst += pow(v[i] - *promedio, 2) / 2; // le sumaremos a la variable desEst la diferencia entre cada numero y el promedio del conjunto al cuadrado dividido en el total de datos
    *devEst = sqrt(*devEst);                     // finalmente de sumar todos esos valores le sacaramos la raiz cuadrada a la sumatoria
}

void Swap(double *n1, double *n2) // definicion de la funcion que cambia dos numeros de posicion
{
    double aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}