/*
Autor: Tomas Bravo.
Tipo de Solucion: Ayuda de Sebastian Aguila, funcion que words.

Escribe un programa que lea una línea de texto e imprima el 
número de caracteres, palabras, mayúsculas y minúsculas que componen la línea.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//funciones.
int words(char *cad);
int isletra(char letra);

int main()
{
    char cad[1000]; // declaramos un arreglo dende vamos a guardar el string que nos entreguen

    int mayus = 0, minus = 0;                 // definimos nuestras variable de acumulacion
    printf("Ingrese una linea de texto: \n"); // pedimos que ingresen la string
    scanf("%[^\n]s", cad);                    // leemos y guardamos la cadena
    getchar();                                //  limpiamos el buffer del teclado

    for (int i = 0; i < strlen(cad); i++) // por cada caracter que hay en la cdena entregada
    {
        if (cad[i] >= 'A' && cad[i] <= 'Z') // si es una letra mayuscula
            mayus += 1;                     // sumamos uno a si variable de acumulacion
        if (cad[i] >= 'a' && cad[i] <= 'z') // si es una letra minuscula
            minus += 1;                     // sumamos uno a si variable de acumulacion
    }

    printf("El texto entregado contiene:\n- %ld caracteres\n- %d palabras\n- %d mayusculas\n- %d minusculas\n", strlen(cad), words(cad), mayus, minus);

    return 0;
}

int isletra(char letra) // esta funcion devuelve si una caracter es una letra o no
{

    return ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'));
}

int words(char *cad)
{
    int isWord = 0, cont = 0;             // declaramos una bandera y una variable de acumulacion para la cantidad de palabras
    for (int i = 0; i < strlen(cad); i++) // por cada caracter del string entregado
    {

        if (isletra(*(cad + i))) // verificamos si es una letra
        {
            if (!isWord)    // si lo es pero no estamos una palabra todavia
                isWord = 1; // marcamos que si estanos en una palabra
        }
        else // si no es una letra
        {
            if (isWord) // y estamos una palabra
            {
                isWord = 0; // marcamos que no estamos en una palabra
                cont++;     // y aumentamos nuestro numero de palabras
            }
        }
    }

    if (isWord) // si al terminer de iterar en nuestro string y la bandera que marca si estamos en una palabra es verdadera
    {
        isWord = 0; // la volveremos a falso
        cont++;     // y aumentamos nuestro contador de palabras en 1
    }
    return cont;
}