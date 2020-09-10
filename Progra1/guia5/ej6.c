/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
#include <stdlib.h>

int cuentaRepeticiones(char *palabra, int tam, char c)
{
    int rep = 0;    // inicializamos el valor de repeticiones en 0
    if(tam - 1 >= 0){   // mientras no nos salgamos de los indices permitidos por el arreglo entregado
        if(palabra[tam - 1] == c)   // verificamos si la letra en la ultima posicion respecto al largo entregado es igual al caracter buscado
            rep++;  // de ser asi aumentamos en 1 el contador de repeticiones
        rep = cuentaRepeticiones(palabra,tam -1,c) + rep;   // luego buscamos en la poscion anterior y le sumamos la contidad de repeticiones que hay actualmente del caracter de referencia
    }
    return rep; // finalmente devolvemos la cantidad de repeticiones que hay del caracter de referencia
}