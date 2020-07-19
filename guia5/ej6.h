/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
#include <stdlib.h>

int cuentaRepeticiones(char *palabra, int tam, char c)
{
    int rep = 0;
    if(tam - 1 >= 0){
        if(palabra[tam - 1] == c)
            rep++;
        rep = cuentaRepeticiones(palabra,tam -1,c) + rep;
    }
    return rep;
}