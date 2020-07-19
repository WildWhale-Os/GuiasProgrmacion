/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ej2.h"
#define Error 1e-6

void SwapJugadores(Jugador *j1, Jugador *j2);
void SwapEquipos(Equipo *eq1, Equipo *eq2);
void SwapFanaticos(Fanatico *f1, Fanatico *f2);
void SwapStaff(Staff *s1, Staff *s2);
void OrdenarJugadoresPos(Equipo *eq, int i);
void OrdenarJugadoresNombre(Equipo *eq, int i);
void OrdenarFanaticosAgresividad(Equipo *eq, int i);
void OrdenarFanaticosNombre(Equipo *eq, int i);
void OrdenarStaffRol(Equipo *eq, int i);
void OrdenarStaffNombre(Equipo *eq, int i);
void OrdenarEquiposNombre(Equipo *eq, int i);

void OrdenarDB(Equipo *equipos)
{ // por cada equipo en el arreglo equipos
    for (int i = 0; i < sizeof(equipos) / sizeof(Equipo) - 1; i++)
    {
        //ordenar jugadores por su posicion
        OrdenarJugadoresPos(equipos, i);
        //ordenar jugadores por su nombre si tienen la misma posicion
        OrdenarJugadoresNombre(equipos, i);
        // ordenar de forma ascendente a los fanaticos por su agresividad
        OrdenarFanaticosAgresividad(equipos, i);
        //Ordenar a los fanaticos con la misma agresividad en orden alfabetico
        OrdenarFanaticosNombre(equipos, i);
        //ordenar staff por rol
        OrdenarStaffRol(equipos, i);
        // ordenar a las personas del staff con el mismo rol segun el alfabeto.
        OrdenarStaffNombre(equipos, i);
        // ordenamos los equipos por nombre
        OrdenarEquiposNombre(equipos, i);
    }
}

void SwapJugadores(Jugador *j1, Jugador *j2)
{
    Jugador aux = *(j1);
    *(j1) = *(j2);
    *(j2) = aux;
}

void SwapEquipos(Equipo *eq1, Equipo *eq2)
{
    Equipo aux = *(eq1);
    *(eq1) = *(eq2);
    *(eq2) = aux;
}

void SwapFanaticos(Fanatico *f1, Fanatico *f2)
{
    Fanatico aux = *(f1);
    *(f1) = *(f2);
    *(f2) = aux;
}

void SwapStaff(Staff *s1, Staff *s2)
{
    Staff aux = *(s1);
    *(s1) = *(s2);
    *(s2) = aux;
}

void OrdenarJugadoresPos(Equipo *eq, int i)
{
    for (int j = 0; j < sizeof(eq[i].jugadores) / sizeof(Jugador *); j++)
    { //ordenamos sus jugadores por posicion.
        for (int k = j + 1; k < sizeof(eq[i].jugadores) / sizeof(Jugador *); k++)
        {
            if (strcmp(eq[i].jugadores[j].posicion, eq[i].jugadores[k].posicion) > 0)
                SwapJugadores(&eq[i].jugadores[j], &eq[i].jugadores[k]);
        }
    }
}

void OrdenarJugadoresNombre(Equipo *eq, int i)
{
    for (int j = 0; j < sizeof(eq[i].jugadores) / sizeof(Jugador *); j++)
    { //ordenamos sus jugadores por posicion.
        for (int k = j + 1; k < sizeof(eq[i].jugadores) / sizeof(Jugador *); k++)
        {
            if (strcmp(eq[i].jugadores[j].nombre, eq[i].jugadores[k].nombre) > 0)
                if (strcmp(eq[i].jugadores[j].posicion, eq[i].jugadores[k].posicion) == 0)
                    SwapJugadores(&eq[i].jugadores[j], &eq[i].jugadores[k]);
        }
    }
}

void OrdenarFanaticosAgresividad(Equipo *eq, int i)
{
    for (int j = 0; j < sizeof(eq[i].fanaticos) / sizeof(Fanatico *); j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < sizeof(eq[i].fanaticos) / sizeof(Fanatico *); k++)
        {
            if (eq[i].fanaticos[k].agresividad - eq[i].fanaticos[j].agresividad > 0)
                SwapFanaticos(&eq[i].fanaticos[j], &eq[i].fanaticos[k]);
        }
    }
}

void OrdenarFanaticosNombre(Equipo *eq, int i)
{
    for (int j = 0; j < sizeof(eq[i].fanaticos) / sizeof(Fanatico *); j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < sizeof(eq[i].fanaticos) / sizeof(Fanatico *); k++)
        {
            if (fabs(eq[i].fanaticos[j].agresividad - eq[i].fanaticos[k].agresividad) < Error)
                if (strcmp(eq[i].fanaticos[j].nombre, eq[i].fanaticos[k].nombre) > 0)
                    SwapFanaticos(&eq[i].fanaticos[j], &eq[i].fanaticos[k]);
        }
    }
}

void OrdenarStaffRol(Equipo *eq, int i)
{
    for (int j = 0; j < sizeof(eq[i].staff) / sizeof(Staff *); j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < sizeof(eq[i].staff) / sizeof(Staff *); k++)
        {
            if (strcmp(eq[i].staff[j].rol, eq[i].staff[k].rol) > 0)
                SwapStaff(&eq[i].staff[j], &eq[i].staff[k]);
        }
    }
}

void OrdenarStaffNombre(Equipo *eq, int i)
{
    for (int j = 0; j < sizeof(eq[i].staff) / sizeof(Staff *); j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < sizeof(eq[i].staff) / sizeof(Staff *); k++)
        {
            if (strcmp(eq[i].staff[j].rol, eq[i].staff[k].rol) == 0)
                if (strcmp(eq[i].staff[j].nombre, eq[i].staff[k].nombre) > 0)
                    SwapStaff(&eq[i].staff[j], &eq[i].staff[k]);
        }
    }
}

void OrdenarEquiposNombre(Equipo *eq, int i)
{
    for (int j = i + 1; j < sizeof(eq) / sizeof(Equipo *); j++)
    {

        if (strcmp(eq[i].nombre, eq[j].nombre) > 0)
            SwapEquipos(&eq[i], &eq[j]);
    }
}
