/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
#include "ej2.h"

void ImprimirJugadores(Equipo *eq)
{
   
    int jcant = eq->numJugadores[0] + eq->numJugadores[1] + eq->numJugadores[2] + eq->numJugadores[3];
    for(int j = 0; j < jcant; ++j)
    {
        Jugador player = eq->jugadores[j];
        printf("Nombre: %s\n", player.nombre);
        printf("\tEdad: %d\n",player.edad);
        printf("\tPosicion: %s\n", player.posicion);
        printf("\tRegate: %f\n", player.regate);
        printf("\tDefensa: %f\n", player.defensa);
        printf("\tReflejos: %f\n", player.reflejos);
        printf("\tVelocidad: %f\n", player.velocidad);
        printf("\tDureza: %f\n", player.dureza);   
        printf("\tResistencia: %f\n", player.defensa);
    }
}

void ImprimirStaff(Equipo *eq)
{
    
    int scant = eq->numStaff[0] + eq->numStaff[1] + eq->numStaff[2] + eq->numStaff[3] + eq->numStaff[4] + eq->numStaff[5];
    for(int j = 0; j < scant; ++j)
    {
        Staff staff = eq->staff[j];
        printf("Nombre: %s\n",staff.nombre);
        printf("\tEdad: %d\n",staff.edad);
        printf("\tRol: %s\n", staff.rol);
        printf("\tExperiencia: %d\n", staff.experriencia);
    }
}

void ImprimirFanaticos(Equipo *eq)
{
    for (int j = 0; j < eq->numFanaticos; j++)
    {
        Fanatico fan = eq->fanaticos[j];
        printf("Nombre: %s\n",fan.nombre);
        printf("\tEdad: %d\n", fan.edad);
        printf("\tAgresividad: %lf\n",fan.agresividad);
    }
    
}

void ImprimirDB(Equipo *eq)
{
    for(int i = 0; i < sizeof(eq)/sizeof(Equipo*); ++i)
    {
        Equipo team = eq[i];
        printf("----------------------------\n");
        printf("\t\t\tMiembros del Equipo %s\n",team.nombre);
        printf("----------------------------\n");
        printf("\t\tJugadores: \n");
        ImprimirJugadores(&team);
        printf("\t\tMiembros del Staff:\n");
        ImprimirStaff(&team);
        printf("\t\tFans\n");
        ImprimirFanaticos(&team);
    }
}