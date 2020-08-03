/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
// Structs ejercicio 1
typedef struct
{
    char nombre[100]; 
    char edad;
    double agresividad;
}Fanatico;

typedef struct
{
    char nombre [100];
    char edad;
    char posicion[10];
    float regate;
    float defensa;
    float reflejos;
    float velocidad;
    float dureza;
    float resistencia;
    
}Jugador;

typedef struct
{
    char nombre[100];
    char edad;
    char rol[30];
    char experriencia;

}Staff;

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
}Equipo;
// funcion que imprime los juagdores de un equipo
void ImprimirJugadores(Equipo *eq)
{   // calculamos el numnero total de jugadores
    int jcant = eq->numJugadores[0] + eq->numJugadores[1] + eq->numJugadores[2] + eq->numJugadores[3];
    for (int j = 0; j < jcant; ++j)
    {   // por cada jugador
        Jugador player = eq->jugadores[j];
        printf("\t%d)\tNombre: %s\n", j + 1, player.nombre);    // imprimimo el valor de su atributo nombre
        printf("\t\tPosicion: %s\n", player.posicion);  // imprimimo el valor de su atributo posicion
        printf("\t\tEdad: %u\n", player.edad);  // imprimimo el valor de su atributo edad
        printf("\t\tRegate: %f\n", player.regate);  // imprimimo el valor de su atributo regate
        printf("\t\tDefensa: %f\n", player.defensa);    // imprimimo el valor de su atributo defensa
        printf("\t\tReflejos: %f\n", player.reflejos);  // imprimimo el valor de su atributo reflejos
        printf("\t\tVelocidad: %f\n", player.velocidad);    // imprimimo el valor de su atributo velocidad
        printf("\t\tDureza: %f\n", player.dureza);  // imprimimo el valor de su atributo dureza
        printf("\t\tResistencia: %f\n", player.resistencia); // imprimimo el valor de su atributo resistencia    
        printf("\n");
    }
    printf("\n");
}
//Funcion que imprimime toda la informacion de los miembros del staff
void ImprimirStaff(Equipo *eq)
{   // Calculamos el total de miembros que hay en el staff del equipo
    int staffCant = eq->numStaff[0] + eq->numStaff[1] + eq->numStaff[2] + eq->numStaff[3] + eq->numStaff[4] + eq->numStaff[5];
    for (int j = 0; j < staffCant; ++j)
    {   // Por cada staff en el equipo
        Staff staff = eq->staff[j];
        printf("\t%d)\tNombre: %s\n", j + 1,staff.nombre);  // imprimimo el valor de su atributo nombre
        printf("\t\tEdad: %u\n", staff.edad);   // imprimimo el valor de su atributo edad
        printf("\t\tRol: %s\n", staff.rol); // imprimimo el valor de su atributo rol
        printf("\t\tExperiencia: %u\n", staff.experriencia);    // imprimimo el valor de su atributo experiencia
    }
}
// funcion que imprime toda la informacion de la fanaticos de un equipo
void ImprimirFanaticos(Equipo *eq)
{   // por cada una de los fanaticos de un equipo
    for (int j = 0; j < eq->numFanaticos; j++)
    {
        Fanatico fan = eq->fanaticos[j];
        printf("\t%d)\tNombre: %s\n", j + 1,fan.nombre);    // imprimimo el valor de si atributo nombre
        printf("\t\tEdad: %u\n", fan.edad); // imprimimo el valor de si atributo edad
        printf("\t\tAgresividad: %lf\n", fan.agresividad);  // imprimimo el valor de si atributo agresividad
    }
}
// funcion que imprime toda la informacion de una base de datos
void ImprimirDB(Equipo *eq, int *numEquipos)
{
    for (int i = 0; i < *numEquipos; ++i)
    {   // por cada unan de los equipos en la base de datos
        Equipo team = eq[i];
        printf("-------------------------------------------------------------------------------\n");
        printf("\t\t\tMiembros del Equipo %s\n", team.nombre);  // imprimimos el nombre del equipo
        printf("-------------------------------------------------------------------------------\n");
        printf("\t\t\t\tAño de Fundacion: %d\n",team.anyoFundacion);    // imprimimos el anyo de fundacion del equipo
        printf("\n");
        printf("\tJugadores: \n");
        printf("\n");
        ImprimirJugadores(&team);   // imprimimos los datos de los jugadores del equipo
        printf("\n");
        printf("\tStaff:\n");
        printf("\n");
        ImprimirStaff(&team);   // imprimimos los datos de los miembros del staff del equipo
        printf("\n");
        printf("\tFans:\n");
        printf("\n");
        ImprimirFanaticos(&team);   // finalmente imprimimos los datos de los fanaticos del equipo
        printf("\n");
    }
}