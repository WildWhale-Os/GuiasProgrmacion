/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define ERROR 1e-8

char *nombresPersonas[] = {"Maria",
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
                           "Martin",
                           "Pablo",
                           "Alejandro",
                           "Alvaro",
                           "Mateo"};
                           
char *nombreEquipos[] = {"Bayern Munich",
                         "FC Barcelona",
                         "Atletico Madrid",
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
                         "Universidad Catolica",
                         "Universidad de Chile",
                         "Sevilla FC",
                         "Chicago Fire",
                         "FC Dallas"};

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

void Swap(int *num1, int *num2);
Fanatico *crearFanaticos(int numFanaticos);
Staff *crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc);
Jugador *crearJugadores(int numArq, int numDef, int numCent, int numDel);
Equipo *crearEquipo(int numEquipos, int fancant);
void liberarFanaticos(Fanatico *fans);
void liberarStaff(Staff *staff);
void liberarJugadores(Jugador *jugadores);
void liberarEquipos(Equipo *equipos, int numEquipos);
void OrdenarDB(Equipo *equipos, int *numEquipos);
void SwapJugadores(Jugador *j1, Jugador *j2);
void SwapEquipos(Equipo *eq1, Equipo *eq2);
void SwapFanaticos(Fanatico *f1, Fanatico *f2);
void SwapStaff(Staff *s1, Staff *s2);
void OrdenarJugadoresPos(Equipo *eq);
void OrdenarJugadoresNombre(Equipo *eq);
void OrdenarFanaticosAgresividad(Equipo *eq);
void OrdenarFanaticosNombre(Equipo *eq);
void OrdenarStaffRol(Equipo *eq);
void OrdenarStaffNombre(Equipo *eq);
void OrdenarEquiposNombre(Equipo *eq, int *numEquipos);
void ImprimirJugadores(Equipo *eq);
void ImprimirStaff(Equipo *eq);
void ImprimirFanaticos(Equipo *eq);
void ImprimirDB(Equipo *eq, int *numEquipos);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int minFan, maxFan, numEquipos;
    printf("Cuantos equipos quiere que se generen en la base de datos: ");
    scanf("%d", &numEquipos);
    while (numEquipos < 0)
    {
        printf("No se puede crear un numero negativo de equipos, ingrese un numero mayor a igual a 0: ");
        scanf("%d", &numEquipos);
    }
    printf("Ingrese un minimo y un maximo de fanaticos en una misma linea que quiere que tenga cada equipo: ");
    scanf("%d%d", &minFan, &maxFan);
    if (minFan > maxFan)
        Swap(&minFan, &maxFan);
    int fancant = minFan + (rand() % (maxFan - minFan));
    printf("numero de fanaticos %d\n", fancant);
    Equipo *eq = crearEquipo(numEquipos, fancant);
    ImprimirDB(eq, &numEquipos);
    OrdenarDB(eq, &numEquipos);
    printf("\t\t---------------> Base de datos Ordenada <---------------\n\n");
    ImprimirDB(eq, &numEquipos);
    liberarEquipos(eq, numEquipos);

    return 0;
}

void Swap(int *num1, int *num2)
{
    int aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

Fanatico *crearFanaticos(int numFanaticos)
{
    Fanatico *fanaticos = (Fanatico *)malloc(numFanaticos * sizeof(Fanatico));
    for (int i = 0; i < numFanaticos; ++i)
    {
        strcpy(fanaticos[i].nombre, nombresPersonas[rand() % 21]);
        fanaticos[i].edad = 18 + rand() % 62;
        fanaticos[i].agresividad = (rand() % 100) / 7;
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
    int numStaff = numDT + numPrepArq + numPrepFis + numAsis + numFisio + numDoc;
    Staff *staff = NULL;
    staff = (Staff *)malloc((numStaff) * sizeof(Staff));
    for (int i = 0; i < numStaff; i++)
    {
        strcpy(staff[i].nombre, nombresPersonas[rand() % 21]);
        staff[i].edad = 18 + rand() % 62;
        staff[i].experriencia = rand() % 61;
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
    Jugador *jugadores = NULL;
    jugadores = (Jugador *)malloc((numArq + numDef + numCent + numDel) * sizeof(Jugador));
    for (int i = 0; i < (numArq + numDef + numCent + numDel); ++i)
    {
        strcpy(jugadores[i].nombre, nombresPersonas[rand() % 21]);
        jugadores[i].edad = 18 + rand() % (40 - 18);
        jugadores[i].regate = (rand() % 301) / 7;
        jugadores[i].defensa = (rand() % 301) / 7;
        jugadores[i].reflejos = (rand() % 301) / 7;
        jugadores[i].velocidad = (rand() % 301) / 7;
        jugadores[i].dureza = (rand() % 301) / 7;
        jugadores[i].resistencia = (rand() % 301) / 7;
        if (i < numArq)
            strcpy(jugadores[i].posicion, "Arquero");
        else if (i - numArq < numDef)
            strcpy(jugadores[i].posicion, "Defensa");
        else if (i - (numArq + numDef) < numCent)
            strcpy(jugadores[i].posicion, "Medio");
        else
            strcpy(jugadores[i].posicion, "Delantero");
    }
    return jugadores;
}

void liberarJugadores(Jugador *jugadores)
{
    free(jugadores);
    jugadores = NULL;
}

Equipo *crearEquipo(int numEquipos, int fancant)
{
    Equipo *equipos = NULL;
    equipos = (Equipo *)malloc(numEquipos * sizeof(Equipo));
    for (int i = 0; i < numEquipos; i++)
    {
        equipos[i].numFanaticos = fancant;

        equipos[i].numJugadores[0] = 3;
        equipos[i].numJugadores[1] = 6;
        equipos[i].numJugadores[2] = 7;
        equipos[i].numJugadores[3] = 6;

        equipos[i].numStaff[0] = 1;
        equipos[i].numStaff[1] = 1;
        equipos[i].numStaff[2] = 1;
        equipos[i].numStaff[3] = 2;
        equipos[i].numStaff[4] = 2;
        equipos[i].numStaff[5] = 1;

        strcpy(equipos[i].nombre, nombreEquipos[rand() % 19]);

        equipos[i].anyoFundacion = (rand() % 1001);
        equipos[i].staff = crearStaff(equipos[i].numStaff[0], equipos[i].numStaff[1], equipos[i].numStaff[2], equipos[i].numStaff[3], equipos[i].numStaff[4], equipos[i].numStaff[5]);

        equipos[i].jugadores = crearJugadores(equipos[i].numJugadores[0], equipos[i].numJugadores[1], equipos[i].numJugadores[2], equipos[i].numJugadores[3]);

        equipos[i].fanaticos = crearFanaticos(equipos[i].numFanaticos);
    }

    // for(int i = 0; i < numEquipos; ++i)
    //     for(int j = 0; j < numEquipos; ++j){
    //         char *dif;
    //         sprintf(dif,"%d",j);
    //         if(strcmp(equipos[i].nombre,equipos[j].nombre) == 0 && i != j)
    //             strcat(equipos[j].nombre,dif);
    //     }
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

void OrdenarDB(Equipo *equipos, int *numEquipos)
{ // por cada equipo en el arreglo equipos
    for (int i = 0; i < *numEquipos; i++)
    {
        //ordenar jugadores por su posicion
        OrdenarJugadoresPos(&equipos[i]);
        //ordenar jugadores por su nombre si tienen la misma posicion
        OrdenarJugadoresNombre(&equipos[i]);
        // ordenar de forma ascendente a los fanaticos por su agresividad
        OrdenarFanaticosAgresividad(&equipos[i]);
        //Ordenar a los fanaticos con la misma agresividad en orden alfabetico
        OrdenarFanaticosNombre(&equipos[i]);
        //ordenar staff por rol
        OrdenarStaffRol(&equipos[i]);
        // ordenar a las personas del staff con el mismo rol segun el alfabeto.
        OrdenarStaffNombre(&equipos[i]);
    }
    // ordenamos los equipos por nombre
    OrdenarEquiposNombre(equipos, numEquipos);
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

void OrdenarJugadoresPos(Equipo *eq)
{
    int numPlayers = (eq->numJugadores[0] + eq->numJugadores[1] + eq->numJugadores[2] + eq->numJugadores[3]);
    for (int j = 0; j < numPlayers; j++)
    { //ordenamos sus jugadores por posicion.
        for (int k = j + 1; k < numPlayers; k++)
        {
            if (strcmp(eq->jugadores[j].posicion, eq->jugadores[k].posicion) > 0)
                SwapJugadores(&eq->jugadores[j], &eq->jugadores[k]);
        }
    }
}

void OrdenarJugadoresNombre(Equipo *eq)
{
    int numPlayers = (eq->numJugadores[0] + eq->numJugadores[1] + eq->numJugadores[2] + eq->numJugadores[3]);
    for (int j = 0; j < numPlayers; j++)
    { //ordenamos sus jugadores por posicion.
        for (int k = j + 1; k < numPlayers; k++)
        {
            if (strcmp(eq->jugadores[j].posicion, eq->jugadores[k].posicion) == 0)
                if (strcmp(eq->jugadores[j].nombre, eq->jugadores[k].nombre) > 0)
                    SwapJugadores(&eq->jugadores[j], &eq->jugadores[k]);
        }
    }
}

void OrdenarFanaticosAgresividad(Equipo *eq)
{
    for (int j = 0; j < eq->numFanaticos; j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < eq->numFanaticos; k++)
        {
            if (eq->fanaticos[j].agresividad - eq->fanaticos[k].agresividad > 0)
                SwapFanaticos(&eq->fanaticos[j], &eq->fanaticos[k]);
        }
    }
}

void OrdenarFanaticosNombre(Equipo *eq)
{
    for (int j = 0; j < eq->numFanaticos; j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < eq->numFanaticos; k++)
        {
            if (fabs(eq->fanaticos[j].agresividad - eq->fanaticos[k].agresividad) < ERROR)
                if (strcmp(eq->fanaticos[j].nombre, eq->fanaticos[k].nombre) > 0)
                    SwapFanaticos(&eq->fanaticos[j], &eq->fanaticos[k]);
        }
    }
}

void OrdenarStaffRol(Equipo *eq)
{
    int numStaff = (eq->numStaff[0] + eq->numStaff[1] + eq->numStaff[2] + eq->numStaff[3] + eq->numStaff[4] + eq->numStaff[5]);
    for (int j = 0; j < numStaff; j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < numStaff; k++)
        {
            if (strcmp(eq->staff[j].rol, eq->staff[k].rol) > 0)
                SwapStaff(&eq->staff[j], &eq->staff[k]);
        }
    }
}

void OrdenarStaffNombre(Equipo *eq)
{
    int numStaff = (eq->numStaff[0] + eq->numStaff[1] + eq->numStaff[2] + eq->numStaff[3] + eq->numStaff[4] + eq->numStaff[5]);
    for (int j = 0; j < numStaff; j++)
    { //ordenamos sus Fanaticos por Agresividad.
        for (int k = j + 1; k < numStaff; k++)
        {
            if (strcmp(eq->staff->rol, eq->staff[k].rol) == 0)
                if (strcmp(eq->staff[j].nombre, eq->staff[k].nombre) > 0)
                    SwapStaff(&eq->staff[j], &eq->staff[k]);
        }
    }
}

void OrdenarEquiposNombre(Equipo *eq, int *numEquipos)
{
    for (int i = 0; i < *numEquipos; i++)
        for (int j = i + 1; j < *numEquipos; j++)
        {
            if (strcmp(eq[i].nombre, eq[j].nombre) > 0)
                SwapEquipos(&eq[i], &eq[j]);
        }
}

void ImprimirJugadores(Equipo *eq)
{

    int jcant = eq->numJugadores[0] + eq->numJugadores[1] + eq->numJugadores[2] + eq->numJugadores[3];
    for (int j = 0; j < jcant; ++j)
    {
        Jugador player = eq->jugadores[j];
        printf("\t%d)\tNombre: %s\n", j + 1, player.nombre);
        printf("\t\tPosicion: %s\n", player.posicion);
        printf("\t\tEdad: %u\n", player.edad);
        printf("\t\tRegate: %f\n", player.regate);
        printf("\t\tDefensa: %f\n", player.defensa);
        printf("\t\tReflejos: %f\n", player.reflejos);
        printf("\t\tVelocidad: %f\n", player.velocidad);
        printf("\t\tDureza: %f\n", player.dureza);
        printf("\t\tResistencia: %f\n", player.defensa);
        printf("\n");
    }
    printf("\n");
}

void ImprimirStaff(Equipo *eq)
{

    int staffCant = eq->numStaff[0] + eq->numStaff[1] + eq->numStaff[2] + eq->numStaff[3] + eq->numStaff[4] + eq->numStaff[5];
    for (int j = 0; j < staffCant; ++j)
    {
        Staff staff = eq->staff[j];
        printf("\t%d)\tNombre: %s\n", j + 1,staff.nombre);
        printf("\t\tEdad: %u\n", staff.edad);
        printf("\t\tRol: %s\n", staff.rol);
        printf("\t\tExperiencia: %u\n", staff.experriencia);
    }
}

void ImprimirFanaticos(Equipo *eq)
{
    for (int j = 0; j < eq->numFanaticos; j++)
    {
        Fanatico fan = eq->fanaticos[j];
        printf("\t%d)\tNombre: %s\n", j + 1,fan.nombre);
        printf("\t\tEdad: %u\n", fan.edad);
        printf("\t\tAgresividad: %lf\n", fan.agresividad);
    }
}

void ImprimirDB(Equipo *eq, int *numEquipos)
{
    for (int i = 0; i < *numEquipos; ++i)
    {
        Equipo team = eq[i];
        printf("-------------------------------------------------------------------------------\n");
        printf("\t\t\tMiembros del Equipo %s\n", team.nombre);
        printf("-------------------------------------------------------------------------------\n");
        printf("\n");
        printf("\tJugadores: \n");
        printf("\n");
        ImprimirJugadores(&team);
        printf("\n");
        printf("\tStaff:\n");
        printf("\n");
        ImprimirStaff(&team);
        printf("\n");
        printf("\tFans:\n");
        printf("\n");
        ImprimirFanaticos(&team);
        printf("\n");
    }
}