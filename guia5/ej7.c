/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esPalindromo(char *palabra, int tam)
{
    int supLimit = tam - 1, infLimit = strlen(palabra) - tam;   // definimos nuestras dos posiciones en el arreglo a comparar y nuestro valor predeterminado a devolver

    if(tam > 0) // mientras nos encontremos dentro de los indices del arreglo de caracteres
    {
        if(palabra[supLimit] == ' ')    // si el caracter en el puesto mas al final del arreglo es una espacio
        {
            supLimit--; // bajamos una posicion en el mismo 
            tam--;  // y disminuimos en uno el largo del arreglo
        }
        else if (palabra[infLimit] == ' ')  // si el caracter mas cerca del incio es un espacio
        {  
            infLimit--; // nos fijamos en la poscion siguiente hacia el fin del arreglo
            tam--;  // y disminuimos en uno el largo del arreglo
        }

        else if(palabra[infLimit] == palabra[supLimit] || palabra[infLimit] + 32 == palabra[supLimit] ||  palabra[infLimit] - 32 == palabra[supLimit])  // luego nos fijamos que si las letras que se encuentran en las posiciones que estan siendo observadaas sean iguales sin importar si es mayuscula o minuscula
        {
            return esPalindromo(palabra,tam - 1);    // si son iguales ejecutamos la funcion recursivamente para ver el siguiente par de letras
        }
        else
            return 0; // si algun par de letras no es igual retonamos 0
    }
    return 1;

}

int main(int argc, char const *argv[])
{
    int tam;
    printf("De que largo sera la string que sera entregada: ");
    scanf("%d", &tam);
    char str[tam];
    printf("Entregue una string: ");
    scanf("%s", str);
    printf("%d\n",esPalindromo(str,tam));

    return 0;
}
