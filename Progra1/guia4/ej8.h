/*
Autor: Tomas Bravo
Tipo de Solucion: Propia


Escriba la función char palindromo(char* cadena1) que devuelva 
1 si cadena1 es un palı́ndromo y 0 en caso contrario.
*/
#include <stdio.h>
#include <string.h>

char Palindromo(char *cadena1) // definicion de la funcion que verifica si una cadena es un palindromo
{
    int check = 1;                                             // usamos una bandera para saber si es palindromo o no
    for (int i = 0, j = strlen(cadena1) - 1; i <= j; ++i, --j) // recorrermos cadena entregada desde el primer caracter y desde el ultimo caracter hasta que las posicion sea la misma
    {
        if (cadena1[j] == ' ') // si se encuentran espacios avanzamos una posicion
            j--;
        if (cadena1[i] == ' ') // en dependiendo en que direccion se estab recorriendo el arreglo
            i++;
        if (cadena1[i] != cadena1[j] && (cadena1[i] + 32) != cadena1[j] && (cadena1[i] - 32) != cadena1[j]) // si las letras que se encuentran en los extremos son distintas letra ya sea mayuscula o minuscula vasta con qeu solo una sea distinta para que la cadena no sea un palindromo
        {
            check = 0; // de ser asi volvemos nuestra bandera 0
            break;     // y rompemos el ciclo
        }
    }

    return (char)(check + '0'); // finalmente devolvemos la bandera en como un caracter
}