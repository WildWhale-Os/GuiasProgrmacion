#include <stdio.h>
#include <stdlib.h>

int PuedePuebles(int cant, int *materiales) // funcion que ve si se puede contruir un pueblo
{
    if (cant < 5)                                                                                 // dependiendo de la cantidad de pueblos contruidos
        if (materiales[0] >= 1 && materiales[1] >= 1 && materiales[2] >= 1 && materiales[3] >= 1) // y si posee los materiales para contruir un nuevo pueblo
            return 1;

    return 0;
}

int PuedeCiudades(int numPueblos, int cant, int *materiales) // funcion que ve si se puede contruir una ciudad
{
    if (cant < 4 && numPueblos != 0)                  // depdendiendo de la cantidad de ciuddades contruidas y si tiene pueblos que pueda reemplazar por una cuidad
        if (materiales[2] >= 2 && materiales[4] >= 3) // y si posee los materiales para contruir una ciudad
            return 1;

    return 0;
}

int PuedeCaminos(int cant, int *materiales) // funcion que ve si se puede contruir un camino
{
    if (cant < 15)                                    // dependindiendo de la cantidad de caminos que haya contruido
        if (materiales[0] >= 1 && materiales[1] >= 1) // y si tiene los materiales necesarios
            return 1;

    return 0;
}

int PuedeCartaDesarrollo(int *materiales) // funcion que ve si se puede camprar una carta de desarrollo
{
    if (materiales[2] >= 1 && materiales[3] >= 1 && materiales[4] >= 1) // solo depende de su posee los materiales para comprar un carta de desarrollo
        return 1;

    return 0;
}

int main()
{
    int estructuras[3]; // definimos dos arreglo donde recibiremos las dos lineas que seran ingresadas
    int materiales[5];

    scanf("%d%d%d", &estructuras[0], &estructuras[1], &estructuras[2]);                                  // leemos la primera linea donde de engresan la cantidad de estructuras que tiene un jugador en el tablero
    scanf("%d%d%d%d%d", &materiales[0], &materiales[1], &materiales[2], &materiales[3], &materiales[4]); // leemos la cantidad de cada uno de la distintos materiales que tiene in jugador en la mano

    if (PuedePuebles(estructuras[0], materiales)) // si puede contruir un pueblo
        printf("Puede construir un pueblo\n");

    if (PuedeCiudades(estructuras[0], estructuras[1], materiales)) // si puede contruir una ciudad
        printf("Puede construir una cuidad\n");

    if (PuedeCaminos(estructuras[2], materiales)) // si puede controir un camino
        printf("Puede construir un camino\n");

    if (PuedeCartaDesarrollo(materiales)) // si puedo comprar una carta de desarrollo
        printf("Puede comprar una carta de desarrollo\n");

    if (!PuedePuebles(estructuras[0], materiales) && !PuedeCiudades(estructuras[0], estructuras[1], materiales) && !PuedeCaminos(estructuras[2], materiales) && !PuedeCartaDesarrollo(materiales))
        printf("No puede construir nada\n"); // si no puede contruir nada

    return 0;
}