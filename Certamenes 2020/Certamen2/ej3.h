#include <stdio.h>
#include <stdlib.h>

int cont = 0; //variable de control de ejecucion recursiva

int ContarCaracteres(char *cadena) // funcion que calcula el largo de una cadena (reemplazo strlen)
{
    int caracteres = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
        caracteres++;

    return caracteres;
}

int contadorVocales(char *cadena)
{
    int vocales = 0; // contador de vocales

    if (cont < ContarCaracteres(cadena)) // mientras nuestra variables de control sea menor que el largo de la cadena
    {
        switch (cadena[cont]) // checkeamos el caracter en la posicion cont de la cadena
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            cont++;                                // si es una vocal de cualquier tipo aumentamos la variable de control en 1
            vocales = contadorVocales(cadena) + 1; // ejecutamos recurisivamente la funcion y le sumamos 1
            break;
        default:                               // si no es una vocal
            cont++;                            // aumentamos la variabnle de control en 1
            vocales = contadorVocales(cadena); // y ejecutamos la funcion recursimante pero sin sumarle 1 ya que al letra en la posicion actual no es una vocal
            break;
        }
    }

    return vocales; // finalmente devolvemos contador de vocales
}