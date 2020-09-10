/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba una función int longitudPalabraMasLarga(int n, char crucigrama[n][n]) 
que recibe una matriz de caracteres que guarda la información de un crucigrama. 
Cada casilla de la matriz puede contener una letra minúscula o el caracter '-', 
que significa una celda bloqueada. Cada palabra del crucigrama puede ser horizontal 
(de izquierda a derecha) o vertical (de arriba a abajo) y puede comenzar o bien en 
una celda exterior o justo después (a la derecha o abajo) de una celda bloqueada. 
La función deberá devolver la longitud de la palabra más larga del crucigrama.

*/
#include <stdio.h>
#include <stdlib.h>

int LongitudPalabraMasLarga(int n, char crucigrama[n][n]) // definicion de la funcion que busca la palabra mas larga escrita dentro de una matriz cuadrada de orden n
{
    int cont = 0;               // definimos la variable  donde guardaremos el largo de la palabras hasta que sea el mayor largo posible
    for (int i = 0; i < n; ++i) // por cada fila y columna
    {
        int lenColum = 0;           // declaramos una variable para guardar el largo de la palabra es la columna actual
        int lengRow = 0;            // delcaramos una variable para guardar el largo de la palabra en la fila actual
        for (int j = 0; j < n; j++) // por cada elemento de cada fila y columna
        {

            if (crucigrama[i][j] >= 'a' && crucigrama[i][j] <= 'z') // por cada caracter dentro de la fila nos fijamos si es una letra mayuscula
                lengRow++;                                          // de ser asi aumentamos el contador de la palabra de la fila actual
            else if (crucigrama[i][j] == '-')                       // por otra parte si el caracter es un -
            {
                if (lengRow > cont) // lo comparamos con el valor actual de cont
                    cont = lengRow; // y lengrow es mayor que cont cambiamos el valor de cont

                lengRow = 0; // y volvemos a 0 el valor de lengrow
            }
            if (crucigrama[j][i] >= 'a' && crucigrama[j][i] <= 'z') // por cada columna hacemos lo mismo
                lenColum++;
            else if (crucigrama[j][i] == '-')
            {
                if (lenColum > cont)
                    cont = lenColum;

                lenColum = 0;
            }
        }
        if (lenColum > cont) // al final comparamos tanto el largo de la ultima palabra leida tanto por fila
            cont = lenColum;
        if (lengRow > cont) // como por columana y y si es mas grande que el valor de cont se cambia el valor de cont por el valor mas grande
            cont = lengRow;
    }

    return cont; // finalmente la funcion devuelve el valor correspondiente al larga dentro de la matriz de cracteres.
}