#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long long frecuencia;        // Frecuencia del procesador eh Hz
    long long memoria;           // Memoria RAM, en Bytes
    char modeloProcesador[200];  // Identificador del procesador
    long long frecuenciaMemoria; // Frecuencia a la que trabaja la memoria RAM
} Caracteristicas;

typedef struct
{
    char marca[200];           // Marca del equipo
    char nombreComercial[200]; // Nombre comercial del equipo
    char tipo[200];            // Tipo de equipo: celular, tablet, notebook, escritorio, etc
    Caracteristicas *specs;    // Especificaciones tecnicas del equipo
    double costoPromedio;      // Costo promedio del equipo en los distintos distribuidores
} Equipo;

double frecuenciaPromedioPorTipo(int n, Equipo *equipos, char *marca, char *tipo)
{
    double fp = 0, cont = 0;                                                    // inicalizasom contadores
    for (int i = 0; i < n; ++i)                                                 // por cada equipo en el arreglo
        if (!strcmp(equipos[i].marca, marca) && !strcmp(equipos[i].tipo, tipo)) // verifiacamos que sean del tipo y marca pedido
        {
            fp += equipos[i].specs->frecuencia; // si son de la marca y tipo pedido le sumamas a nuestra variable de frecuencia promedio su freceuncia
            cont++;                             // y aumentamos en uno el contador de equipos que poseen esa marca y tipo de equipo
        }

    return fp / cont; // finalmente retornamos la suma de todas las frecuencias devidido el total de equipos que eran de la marca y tipo indicados
}