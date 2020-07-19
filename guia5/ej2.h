/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
#include <stdlib.h>
#include "ej1.h"
#include <time.h>
#include <string.h>

char *nombresPersonas[] = {"María",
                           "Carmen",
                           "Josefa",
                           "Isabel",
                           "Laura",
                           "Antonio ",
                           "Jose",
                           "Manuel",
                           "Francisco",
                           "David",
                           "Juan",
                           "Javier",
                           "Daniel",
                           "Lucia",
                           "Martina",
                           "Hugo",
                           "Martín",
                           "Pablo",
                           "Alejandro",
                           "Álvaro",
                           "Mateo"};
char *nombreEquipos[] = {"Bayern Munich",
                         "FC Barcelona",
                         "Atlético Madrid",
                         "Real Madrid CF",
                         "Chelsea",
                         "Liverpool",
                         "Manchester United",
                         "Manchester City",
                         "Juventus",
                         "Milan",
                         "Napoli",
                         "Cruzeiro",
                         "Flamengo",
                         "Santos",
                         "Colo Colo",
                         "Universidad Católica",
                         "Universidad de Chile",
                         "Sevilla FC",
                         "Chicago Fire",
                         "FC Dallas"};

Fanatico *crearFanaticos(int numFanaticos)
{
    srand(time(NULL));
    Fanatico *fanaticos = (Fanatico *)malloc(numFanaticos * sizeof(Fanatico));
    for (int i = 0; i < numFanaticos; ++i)
    {
        strcpy(fanaticos[i].nombre, nombresPersonas[rand() % 21]);
        fanaticos[i].edad = 10 + rand() % 80;
        fanaticos[i].agresividad = rand() % 100;
    }

    return fanaticos;
}

void liberarFanaticos(Fanatico *fans)
{
    free(fans);
    fans = NULL;
}

Staff *crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc)
{
    srand(time(NULL));
    int numStaff = numDT + numPrepArq + numPrepFis + numAsis + numFisio + numDoc;
    char nombre[] = "Roberto";
    Staff *staff = NULL;
    staff = (Staff *)malloc((numStaff) * sizeof(Staff));
    for (int i = 0; i < numStaff; i++)
    {
        strcpy(staff[i].nombre, nombre);
        staff[i].edad = 18 + rand() % 32;
        staff[i].experriencia = rand() % 255;
        if (i < numDT)
            strcpy(staff[i].rol, "DT");
        else if (i - numDT < numPrepArq)
            strcpy(staff[i].rol, "Preparador de Arqueros");
        else if (i - (numDT + numPrepArq) < numPrepFis)
            strcpy(staff[i].rol, "Preparador Fisico");
        else if (i - (numDT + numPrepArq + numPrepFis) < numAsis)
            strcpy(staff[i].rol, "Asistente");
        else if (i - (numDT + numPrepArq + numPrepFis + numAsis) < numFisio)
            strcpy(staff[i].rol, "Fisioterapeuta");
        else if (i - (numDT + numPrepArq + numPrepFis + numAsis + numFisio) < numDoc)
            strcpy(staff[i].rol, "Doctor");
    }

    return staff;
}

void liberarStaff(Staff *staff)
{
    free(staff);
    staff = NULL;
}

Jugador *crearJugadores(int numArq, int numDef, int numCent, int numDel)
{
    srand(time(NULL));
    Jugador *jugadores = NULL;
    jugadores = (Jugador *)malloc((numArq + numDef + numCent + numDel) * sizeof(Jugador));
    for (int i = 0; i < (numArq + numDef + numCent + numDel); ++i)
    {
        strcpy(jugadores[i].nombre, nombresPersonas[rand() % 21]);
        jugadores[i].edad = 18 + rand() % 22;
        jugadores[i].regate = (rand() % 301) / 3;
        jugadores[i].defensa = (rand() % 301) / 3;
        jugadores[i].reflejos = (rand() % 301) / 3;
        jugadores[i].velocidad = (rand() % 301) / 3;
        jugadores[i].dureza = (rand() % 301) / 3;
        jugadores[i].resistencia = (rand() % 301) / 3;
        if (i < numArq)
            strcpy(jugadores[i].posicion, "Arquero");
        else if (i - numArq < numDef)
            strcpy(jugadores[i].posicion, "Defensa");
        else if (i - (numArq + numDef) < numCent)
            strcpy(jugadores[i].posicion, "Medio");
        else if (i - (numArq + numDef + numCent) < numDel)
            strcpy(jugadores[i].posicion, "Delantero");
    }
    return jugadores;
}

void liberarJugadores(Jugador *jugadores)
{
    free(jugadores);
    jugadores = NULL;
}

Equipo *crearEquipo(int numEquipos)
{
    srand(time(NULL));
    Equipo *equipos = NULL;
    equipos = (Equipo *)malloc(numEquipos * sizeof(Equipo));
    for (int i = 0; i < numEquipos; i++)
    {
        equipos[i].numFanaticos = rand() % 100;
        for (int j = 0; j < 4; ++j)
            equipos[i].numJugadores[j] = rand() % 23;
        for (int j = 0; j < 6; ++j)
            equipos[i].numStaff[j] = rand() % 23;
        strcpy(equipos[i].nombre, nombreEquipos[rand() % 21]);
        equipos[i].anyoFundacion = (rand() % 1001);
        equipos[i].staff = crearStaff(equipos[i].numStaff[0], equipos[i].numStaff[1], equipos[i].numStaff[2], equipos[i].numStaff[3], equipos[i].numStaff[4], equipos[i].numStaff[5]);
        equipos[i].jugadores = crearJugadores(equipos[i].numJugadores[0], equipos[i].numJugadores[1], equipos[i].numJugadores[2], equipos[i].numJugadores[3]);
        equipos[i].fanaticos = crearFanaticos(equipos[i].numFanaticos);
    }
    for(int i = 0; i < numEquipos; ++i)
        for(int j = i+1; j < numEquipos; ++j){
            char *dif;
            sprintf(dif,"%d",j);
            if(strcmp(equipos[i].nombre,equipos[j].nombre) == 0)
                strcat(equipos[j].nombre,dif);
        }
            
    return equipos;
}

void liberarEquipos(Equipo *equipos, int numEquipos)
{
    for (int i = 0; i < numEquipos; ++i)
    {
        liberarJugadores(equipos[i].jugadores);
        liberarFanaticos(equipos[i].fanaticos);
        liberarStaff(equipos[i].staff);
    }
    free(equipos);
    equipos = NULL;
}