/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
// lista de nombres de personas
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
// lista de nombres de equipos
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
// funcion que crea un arreglo de numFnaticos de forma aleatoria
Fanatico *crearFanaticos(int numFanaticos)
{
    srand(time(NULL));
    Fanatico *fanaticos = (Fanatico *)malloc(numFanaticos * sizeof(Fanatico));  // pedimos la cantidad necesario de memoria para almecenar numFanaticos dentro de nuestro arrglo
    for (int i = 0; i < numFanaticos; ++i)  // por cada una de las posiciones del arreglo
    {
        strcpy(fanaticos[i].nombre, nombresPersonas[rand() % 21]);  // le entregamos un nombre aleatorio a nuestro fanatico
        fanaticos[i].edad = 10 + rand() % 80;   // le damos una edad aleatoria a nuestro fanatico entre 10 y 90 
        fanaticos[i].agresividad = rand() % 101;    // y le damos una agresividad aleatoria ente 0 y 100
    }

    return fanaticos;
}
// funcion que liberara la memoria usada por un puntero a un arreglo de fanaticos
void liberarFanaticos(Fanatico *fans)
{
    free(fans);
    fans = NULL;
}
// funcion que crea de forma aleatoria staff dado una numero de personas por cada rol del staff
Staff *crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc)
{
    srand(time(NULL));
    int numStaff = numDT + numPrepArq + numPrepFis + numAsis + numFisio + numDoc; // calculamos el numero total del staff
    Staff *staff = (Staff *)malloc((numStaff) * sizeof(Staff));  // pedimos la memoria necesaria para almacenar el total de staff pedido 
    for (int i = 0; i < numStaff; i++)  // ahora por cada espacio de nuestro arreglo de staff
    {
        strcpy(staff[i].nombre, nombresPersonas[rand() %21]);   // le damos un nombre aleatorio de nuestra lista de nombres
        staff[i].edad = 18 + rand() % 32;   // le damos una edad aleatoria entre 18 y 50 
        staff[i].experriencia = rand() % 256; // le damos un valor aleatorio de experiencia entre 0 y 255
        if (i < numDT)  // si nuestro iterador es menor al numero de DTs pedidos
            strcpy(staff[i].rol, "DT"); // el rol del staff sera DT
        else if (i - numDT < numPrepArq)    // despues de haber creado todos los staff con el rol DT
            strcpy(staff[i].rol, "Preparador de Arqueros"); // se crearan todos los staff con el rol Preparador de arqueros que son requeridos
        else if (i - (numDT + numPrepArq) < numPrepFis) // despues de haber creado todos los staff con el rol de DT y preparador de arqueros que eran requeridos
            strcpy(staff[i].rol, "Preparador Fisico");  // creamos los staff con rol preparadores fisico requerido
        else if (i - (numDT + numPrepArq + numPrepFis) < numAsis)   // despues
            strcpy(staff[i].rol, "Asistente");  // creamos los staff con el rol de asistente que son requeridos
        else if (i - (numDT + numPrepArq + numPrepFis + numAsis) < numFisio) // luego
            strcpy(staff[i].rol, "Fisioterapeuta"); // los staff con rol fisioterapeuta que son requeridos
        else   // y finalmente
            strcpy(staff[i].rol, "Doctor"); // los staff con rol de doctor que son requeridos
    }

    return staff;
}
// funcion que libera la memorio asignada a un puntero de tipo staff
void liberarStaff(Staff *staff)
{
    free(staff);
    staff = NULL;
}
//funcion que crea de forma aleatoria segun el numero de jugadores por posicion que sea entregado
Jugador *crearJugadores(int numArq, int numDef, int numCent, int numDel)
{
    srand(time(NULL));
    Jugador *jugadores = (Jugador *)malloc((numArq + numDef + numCent + numDel) * sizeof(Jugador)); // pedimos memoria suficiente para almecenar todos los jugadadores que se piden
    for (int i = 0; i < (numArq + numDef + numCent + numDel); ++i)  // por poscision de nuestro arreglo de jugadores
    {
        strcpy(jugadores[i].nombre, nombresPersonas[rand() % 21]);  // le entregamos un numbre aleatorio
        jugadores[i].edad = 18 + rand() % 23;   // le damos una edad aleatoria entre 18 y 40
        jugadores[i].regate = (rand() % 300) / 7;   // le entregamos un valor aleatorio a su regate
        jugadores[i].defensa = (rand() % 300) / 7;  // le entregamos un valor aleatorio a su defensa
        jugadores[i].reflejos = (rand() % 300) / 7; // le entregamos un valor aleatorio a su reflejos
        jugadores[i].velocidad = (rand() % 300) / 7;    // le entregamos un valor aleatorio a su velocidad
        jugadores[i].dureza = (rand() % 300) / 7;   // le entregamos un valor aleatorio a su dureza
        jugadores[i].resistencia = (rand() % 300) / 7;  // le entregamos un valor aleatorio a su resistencia
        if (i < numArq) // primero 
            strcpy(jugadores[i].posicion, "Arquero");   // creamos todos los jugadores con poscicion arquero que se piden
        else if (i - numArq < numDef)   // en segundo lugar
            strcpy(jugadores[i].posicion, "Defensa");   // todos los jugadores con posicion defensa que se piden
        else if (i - (numArq + numDef) < numCent)   // en tercer lugar
            strcpy(jugadores[i].posicion, "Medio"); // todos los jugadores con posicion medio que se piden
        else    // finalmente
            strcpy(jugadores[i].posicion, "Delantero"); // todos los jugadores con posicion delantero que se piden
    }
    return jugadores;
}
// funcion que libera la memoria asignada a un puntero de tipo jugador
void liberarJugadores(Jugador *jugadores)
{
    free(jugadores);
    jugadores = NULL;
}
// funcion que crea un numero numEquipos de equipos
Equipo *crearEquipo(int numEquipos)
{
    srand(time(NULL));
    Equipo *equipos = (Equipo *)malloc(numEquipos * sizeof(Equipo)); // pedimos la memoria necesaria para almacenar todos lo equipos pedidos
    for (int i = 0; i < numEquipos; i++)    // despues por cada una de las equipos
    {
        equipos[i].numFanaticos = rand() % 100; // le asignamos un numero aleatorio de fanaticos entre 0 y 99
        for (int j = 0; j < 4; ++j) // por cada posicion que puede tener los jugadores
            equipos[i].numJugadores[j] = rand() % 23;   // le entegamos un valor aleatorio
        for (int j = 0; j < 6; ++j) // por cada rol que puede tener un staff 
            equipos[i].numStaff[j] = rand() % 23; // entregamos un valor aleatorio
        strcpy(equipos[i].nombre, nombreEquipos[rand() % 2]);  // le damos un nombre aleatoria de la lista de numbresEquipos
        equipos[i].anyoFundacion = 1900 + rand() % 121; // le damos un anyo aleatorio de fundacion entre 1900 y 2020
        equipos[i].staff = crearStaff(equipos[i].numStaff[0], equipos[i].numStaff[1], equipos[i].numStaff[2], equipos[i].numStaff[3], equipos[i].numStaff[4], equipos[i].numStaff[5]);  // creamos los staff del equipo
        equipos[i].jugadores = crearJugadores(equipos[i].numJugadores[0], equipos[i].numJugadores[1], equipos[i].numJugadores[2], equipos[i].numJugadores[3]);  // creamos los juagdores del equipos
        equipos[i].fanaticos = crearFanaticos(equipos[i].numFanaticos); // creamos los fanaticos del equipo
    }
    for(int i = 0; i < numEquipos; ++i)
        for(int j = i+1; j < numEquipos; ++j){
            char *dif;
            sprintf(dif,"%d",j);
            if(strcmp(equipos[i].nombre,equipos[j].nombre) == 0)    // si el nombre de dos equipos es igual
                strcat(equipos[j].nombre,dif);  // al segundo en la lista se le agrega un numero para diferenciarlos
        }
            
    return equipos;
}
//funcion que libera la memoria asignada a un puntero de tipo Equipo
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