/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Error 1e-6

// Strutcs Ejercicio 1
typedef struct
{
    char nombre[100];
    char edad;
    double agresividad;
} Fanatico;

typedef struct
{
    char nombre[100];
    char edad;
    char posicion[10];
    float regate;
    float defensa;
    float reflejos;
    float velocidad;
    float dureza;
    float resistencia;

} Jugador;

typedef struct
{
    char nombre[100];
    char edad;
    char rol[30];
    char experriencia;

} Staff;

typedef struct
{
    char nombre[100];
    unsigned int anyoFundacion;
    Staff *staff;
    int numStaff[6];
    Jugador *jugadores;
    int numJugadores[4];
    Fanatico *fanaticos;
    int numFanaticos;
} Equipo;
// funcion que cambia de posicion dos jugadores
void SwapJugadores(Jugador *j1, Jugador *j2)
{
    Jugador aux = *(j1);
    *(j1) = *(j2);
    *(j2) = aux;
}
// funcion que cambia de posicion dos equipos
void SwapEquipos(Equipo *eq1, Equipo *eq2)
{
    Equipo aux = *(eq1);
    *(eq1) = *(eq2);
    *(eq2) = aux;
}
// funcion que cambia de poscion dos fanaticos
void SwapFanaticos(Fanatico *f1, Fanatico *f2)
{
    Fanatico aux = *(f1);
    *(f1) = *(f2);
    *(f2) = aux;
}
// funcion que cambia de posicion dos staff
void SwapStaff(Staff *s1, Staff *s2)
{
    Staff aux = *(s1);
    *(s1) = *(s2);
    *(s2) = aux;
}
// funcion que ordena a los jugadores de un equipo segun su posicion
void OrdenarJugadores(Equipo *eq)
{
    // caculamos el total de jugadores
    int numPlayers = (eq->numJugadores[0] + eq->numJugadores[1] + eq->numJugadores[2] + eq->numJugadores[3]);
    // por cada juagdor
    for (int j = 0; j < numPlayers; j++)
    { // lo comparamos con el un jugador distinto en la lista
        for (int k = j + 1; k < numPlayers; k++)
        { // ordenmaos a los jugadores por si poscion en orden alfabetico
            if (strcmp(eq->jugadores[j].posicion, eq->jugadores[k].posicion) > 0)
                SwapJugadores(&eq->jugadores[j], &eq->jugadores[k]);
        }
    }
    // depsues de que los juagdores esten ordenados por posicion ahora los ordenamos por su nombre en orden alfabetico solo si tienen la misma posicion
    OrdenarJugadoresNombre(eq, &numPlayers);
}
// funcion que ordena los juagdores de un equipo segun su nombre
void OrdenarJugadoresNombre(Equipo *eq, int *numPlayers)
{
    for (int j = 0; j < *numPlayers; j++)
    {
        for (int k = j + 1; k < *numPlayers; k++)
        { // si dos jugaodres tienen la misma poscion
            if (strcmp(eq->jugadores[j].posicion, eq->jugadores[k].posicion) == 0)
                // verificamos que esten ordenados de forma alfabetica
                if (strcmp(eq->jugadores[j].nombre, eq->jugadores[k].nombre) > 0)
                    SwapJugadores(&eq->jugadores[j], &eq->jugadores[k]);
        }
    }
}
// funcion que ordena los fanaticos
void OrdenarFanaticos(Equipo *eq)
{
    for (int j = 0; j < eq->numFanaticos; j++)
    {
        for (int k = j + 1; k < eq->numFanaticos; k++)
        {   // Comparamos dos fanaticos distintos en la lista de fanaticos del equipo los ordenamos de forma ascendente segun su agresividad
            if (eq->fanaticos[j].agresividad - eq->fanaticos[k].agresividad > 0)
                SwapFanaticos(&eq->fanaticos[j], &eq->fanaticos[k]);
        }
    }
    // Despues de haber ordenada a los fanaticos por su agresividad los ordenamos segun su nombre si tienen la misma cantidad de agresividad
    OrdenarFanaticosNombre(eq);
}

void OrdenarFanaticosNombre(Equipo *eq)
{
    for (int j = 0; j < eq->numFanaticos; j++)
    { 
        for (int k = j + 1; k < eq->numFanaticos; k++)
        {   // si la agresidad de dos fanaticos distintos en la lista de fanaticos
            if (fabs(eq->fanaticos[j].agresividad - eq->fanaticos[k].agresividad) < Error)  // tienen la misma agresisvidad 
                if (strcmp(eq->fanaticos[j].nombre, eq->fanaticos[k].nombre) > 0)   // los colocamos en orden alfabetico mirando el nombre de ambos
                    SwapFanaticos(&eq->fanaticos[j], &eq->fanaticos[k]);
        }
    }
}
// funcion que ordena al staff de un equipo
void OrdenarStaff(Equipo *eq)
{
    // Calculamos el numero total de staff en el equipo
    int numStaff = (eq->numStaff[0] + eq->numStaff[1] + eq->numStaff[2] + eq->numStaff[3] + eq->numStaff[4] + eq->numStaff[5]);
    for (int j = 0; j < numStaff; j++)
    {
        for (int k = j + 1; k < numStaff; k++)
        {   // comparamos dos miembros del staff distintos de la lista de staff
            if (strcmp(eq->staff[j].rol, eq->staff[k].rol) > 0) // y los ordenamos en orden alfabetico segun su rol
                SwapStaff(&eq->staff[j], &eq->staff[k]);
        }
    }
    // luego los que tengan igual rol los ordenamos segun su nombre
    OrdenarStaffNombre(eq, &numStaff);
}
// funcion que ordena los miembros del estaff que tiene el mismo rol
void OrdenarStaffNombre(Equipo *eq, int *numStaff)
{
    for (int j = 0; j < *numStaff; j++)
    {
        for (int k = j + 1; k < *numStaff; k++)
        {   // si dos miembros del staff tienen el mismo rol
            if (strcmp(eq->staff[j].rol, eq->staff[k].rol) == 0)
                if (strcmp(eq->staff[j].nombre, eq->staff[k].nombre) > 0)   // los ordenamos segun su nombre de forma alfabetica
                    SwapStaff(&eq->staff[j], &eq->staff[k]);
        }
    }
}
// funcion que ordena los equipos segun sus nombres
void OrdenarEquiposNombre(Equipo *eq, int *numEquipos)
{
    for (int i = 0; i < *numEquipos; i++)
        for (int j = i + 1; j < *numEquipos; j++)
        {   // comparamos dos equipos distintos en el arreglo de equipos
            if (strcmp(eq[i].nombre, eq[j].nombre) > 0) // si el nombre de primero va despues segun el orden alfabetico
                SwapEquipos(&eq[i], &eq[j]);    // los cambiamos de posicion
        }
}
// funcion que ordena el vector de equipos segun las instrucciones dadas
void OrdenarDB(Equipo *equipos, int *numEquipos)
{ // por cada equipo en el arreglo equipos
    for (int i = 0; i < *numEquipos; i++)
    {
        //ordenar jugadores 
        OrdenarJugadores(&equipos[i]);
        // ordenar fanaticos
        OrdenarFanaticos(&equipos[i]);
        //ordenar staff
        OrdenarStaff(&equipos[i]);
    }
    // ordenamos los equipos por nombre
    OrdenarEquiposNombre(equipos, numEquipos);
}