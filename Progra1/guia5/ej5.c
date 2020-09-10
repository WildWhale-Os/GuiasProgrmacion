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
//Lista de nombres de personas
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
// Lista de nombres de equipos
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
// Structs
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

// Declaracion de funciones
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
void OrdenarJugadores(Equipo *eq);
void OrdenarJugadoresNombre(Equipo *eq, int *totalPlayers);
void OrdenarFanaticos(Equipo *eq);
void OrdenarFanaticosNombre(Equipo *eq);
void OrdenarStaff(Equipo *eq);
void OrdenarStaffNombre(Equipo *eq, int *numStaff);
void OrdenarEquiposNombre(Equipo *eq, int *numEquipos);
void ImprimirJugadores(Equipo *eq);
void ImprimirStaff(Equipo *eq);
void ImprimirFanaticos(Equipo *eq);
void ImprimirDB(Equipo *eq, int *numEquipos);
// Definicion de funciones, incluido la funcion main.
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int minFan, maxFan, numEquipos; // definicion de varibales que necesitamos
    printf("Cuantos equipos quiere que se generen en la base de datos: ");
    scanf("%d", &numEquipos); // guardamos la cantidad de equipos a generar en la variable numEquipos
    while (numEquipos <= 0)   // si el numero entregado es negativo o 0
    {
        printf("No se puede crear un numero negativo de equipos o 0 equipos, ingrese un numero mayor a 0: ");
        scanf("%d", &numEquipos); // pedimos y leemos otro numero
    }
    printf("Ingrese un minimo y un maximo de fanaticos en una misma linea que quiere que tenga cada equipo: ");
    scanf("%d%d", &minFan, &maxFan);                     // pedimos cotas para el numero de fans por equipo y las guardamos en sus variables correspondientes
    if (minFan > maxFan)                                 // si se ingresan los numeros al reves en otras palabras que el valor de maxfan sea menor que minfan
        Swap(&minFan, &maxFan);                          // intercambiamos los valores de las variables
    int fancant = minFan + (rand() % (maxFan - minFan)); // calculamos un numero aleatorio de fanaticos por equipo entre los valores de minfan y maxfan
    Equipo *eq = crearEquipo(numEquipos, fancant);       // generamos los equipos
    ImprimirDB(eq, &numEquipos);                         // imprimimos las base de datos desordenada
    OrdenarDB(eq, &numEquipos);                          // ordenamos la base de datos
    printf("\t\t---------------> Base de datos Ordenada <---------------\n\n");
    ImprimirDB(eq, &numEquipos);    // imprimimos la base de datos ordenada
    liberarEquipos(eq, numEquipos); // liberamos la memoria pedida por el programa al OS

    return 0;
}
// funcion para cambiar de posicion dos numeros enteros
void Swap(int *num1, int *num2)
{
    int aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

// funcion que crea un arreglo de numFnaticos de forma aleatoria
Fanatico *crearFanaticos(int numFanaticos)
{
    srand(time(NULL));
    Fanatico *fanaticos = (Fanatico *)malloc(numFanaticos * sizeof(Fanatico)); // pedimos la cantidad necesario de memoria para almecenar numFanaticos dentro de nuestro arrglo
    for (int i = 0; i < numFanaticos; ++i)                                     // por cada una de las posiciones del arreglo
    {
        strcpy(fanaticos[i].nombre, nombresPersonas[rand() % 21]); // le entregamos un nombre aleatorio a nuestro fanatico
        fanaticos[i].edad = 10 + rand() % 80;                      // le damos una edad aleatoria a nuestro fanatico entre 10 y 90
        fanaticos[i].agresividad = rand() % 101;                   // y le damos una agresividad aleatoria ente 0 y 100
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
    Staff *staff = (Staff *)malloc((numStaff) * sizeof(Staff));                   // pedimos la memoria necesaria para almacenar el total de staff pedido
    for (int i = 0; i < numStaff; i++)                                            // ahora por cada espacio de nuestro arreglo de staff
    {
        strcpy(staff[i].nombre, nombresPersonas[rand() % 21]);               // le damos un nombre aleatorio de nuestra lista de nombres
        staff[i].edad = 18 + rand() % 32;                                    // le damos una edad aleatoria entre 18 y 50
        staff[i].experriencia = rand() % 256;                                // le damos un valor aleatorio de experiencia entre 0 y 255
        if (i < numDT)                                                       // si nuestro iterador es menor al numero de DTs pedidos
            strcpy(staff[i].rol, "DT");                                      // el rol del staff sera DT
        else if (i - numDT < numPrepArq)                                     // despues de haber creado todos los staff con el rol DT
            strcpy(staff[i].rol, "Preparador de Arqueros");                  // se crearan todos los staff con el rol Preparador de arqueros que son requeridos
        else if (i - (numDT + numPrepArq) < numPrepFis)                      // despues de haber creado todos los staff con el rol de DT y preparador de arqueros que eran requeridos
            strcpy(staff[i].rol, "Preparador Fisico");                       // creamos los staff con rol preparadores fisico requerido
        else if (i - (numDT + numPrepArq + numPrepFis) < numAsis)            // despues
            strcpy(staff[i].rol, "Asistente");                               // creamos los staff con el rol de asistente que son requeridos
        else if (i - (numDT + numPrepArq + numPrepFis + numAsis) < numFisio) // luego
            strcpy(staff[i].rol, "Fisioterapeuta");                          // los staff con rol fisioterapeuta que son requeridos
        else                                                                 // y finalmente
            strcpy(staff[i].rol, "Doctor");                                  // los staff con rol de doctor que son requeridos
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
    for (int i = 0; i < (numArq + numDef + numCent + numDel); ++i)                                  // por poscision de nuestro arreglo de jugadores
    {
        strcpy(jugadores[i].nombre, nombresPersonas[rand() % 21]); // le entregamos un numbre aleatorio
        jugadores[i].edad = 18 + rand() % 23;                      // le damos una edad aleatoria entre 18 y 40
        jugadores[i].regate = (rand() % 300) / 7;                  // le entregamos un valor aleatorio a su regate
        jugadores[i].defensa = (rand() % 300) / 7;                 // le entregamos un valor aleatorio a su defensa
        jugadores[i].reflejos = (rand() % 300) / 7;                // le entregamos un valor aleatorio a su reflejos
        jugadores[i].velocidad = (rand() % 300) / 7;               // le entregamos un valor aleatorio a su velocidad
        jugadores[i].dureza = (rand() % 300) / 7;                  // le entregamos un valor aleatorio a su dureza
        jugadores[i].resistencia = (rand() % 300) / 7;             // le entregamos un valor aleatorio a su resistencia
        if (i < numArq)                                            // primero
            strcpy(jugadores[i].posicion, "Arquero");              // creamos todos los jugadores con poscicion arquero que se piden
        else if (i - numArq < numDef)                              // en segundo lugar
            strcpy(jugadores[i].posicion, "Defensa");              // todos los jugadores con posicion defensa que se piden
        else if (i - (numArq + numDef) < numCent)                  // en tercer lugar
            strcpy(jugadores[i].posicion, "Medio");                // todos los jugadores con posicion medio que se piden
        else                                                       // finalmente
            strcpy(jugadores[i].posicion, "Delantero");            // todos los jugadores con posicion delantero que se piden
    }
    return jugadores;
}
// funcion que libera la memoria asignada a un puntero de tipo jugador
void liberarJugadores(Jugador *jugadores)
{
    free(jugadores);
    jugadores = NULL;
}
Equipo *crearEquipo(int numEquipos, int fancant)
{
    Equipo *equipos = (Equipo *)malloc(numEquipos * sizeof(Equipo)); // pedimos la memoria necesaria para almacenar todos lo equipos pedidos
    for (int i = 0; i < numEquipos; i++)
    {                                      // Por cada equipo
        equipos[i].numFanaticos = fancant; // le asignamos el numero de fanaticos entregado

        equipos[i].numJugadores[0] = 3; // numeros de aqueros
        equipos[i].numJugadores[1] = 6; // numeros de defensas
        equipos[i].numJugadores[2] = 7; // numero de medios
        equipos[i].numJugadores[3] = 6; // numero de delanteros

        equipos[i].numStaff[0] = 1; // numero de DTs
        equipos[i].numStaff[1] = 1; // numero de preparadores de arqueros
        equipos[i].numStaff[2] = 1; // numeros de preparadores fisicos
        equipos[i].numStaff[3] = 2; // numero de asistentes
        equipos[i].numStaff[4] = 2; // numero de fisioterapeutas
        equipos[i].numStaff[5] = 1; // numero de doctores

        strcpy(equipos[i].nombre, nombreEquipos[rand() % 20]);                                                                                                                         // le damos un nombre aleatoria de la lista de numbresEquipos
        equipos[i].anyoFundacion = 1900 + rand() % 121;                                                                                                                                // le damos un anyo aleatorio de fundacion entre 1900 y 2020
        equipos[i].staff = crearStaff(equipos[i].numStaff[0], equipos[i].numStaff[1], equipos[i].numStaff[2], equipos[i].numStaff[3], equipos[i].numStaff[4], equipos[i].numStaff[5]); // creamos los staff del equipo
        equipos[i].jugadores = crearJugadores(equipos[i].numJugadores[0], equipos[i].numJugadores[1], equipos[i].numJugadores[2], equipos[i].numJugadores[3]);                         // creamos los juagdores del equipos
        equipos[i].fanaticos = crearFanaticos(equipos[i].numFanaticos);                                                                                                                // creamos los fanaticos del equipo
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
        { // Comparamos dos fanaticos distintos en la lista de fanaticos del equipo los ordenamos de forma ascendente segun su agresividad
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
        {                                                                                  // si la agresidad de dos fanaticos distintos en la lista de fanaticos
            if (fabs(eq->fanaticos[j].agresividad - eq->fanaticos[k].agresividad) < ERROR) // tienen la misma agresisvidad
                if (strcmp(eq->fanaticos[j].nombre, eq->fanaticos[k].nombre) > 0)          // los colocamos en orden alfabetico mirando el nombre de ambos
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
        {                                                       // comparamos dos miembros del staff distintos de la lista de staff
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
        { // si dos miembros del staff tienen el mismo rol
            if (strcmp(eq->staff[j].rol, eq->staff[k].rol) == 0)
                if (strcmp(eq->staff[j].nombre, eq->staff[k].nombre) > 0) // los ordenamos segun su nombre de forma alfabetica
                    SwapStaff(&eq->staff[j], &eq->staff[k]);
        }
    }
}
// funcion que ordena los equipos segun sus nombres
void OrdenarEquiposNombre(Equipo *eq, int *numEquipos)
{
    for (int i = 0; i < *numEquipos; i++)
        for (int j = i + 1; j < *numEquipos; j++)
        {                                               // comparamos dos equipos distintos en el arreglo de equipos
            if (strcmp(eq[i].nombre, eq[j].nombre) > 0) // si el nombre de primero va despues segun el orden alfabetico
                SwapEquipos(&eq[i], &eq[j]);            // los cambiamos de posicion
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

// funcion que imprime los juagdores de un equipo
void ImprimirJugadores(Equipo *eq)
{ // calculamos el numnero total de jugadores
    int jcant = eq->numJugadores[0] + eq->numJugadores[1] + eq->numJugadores[2] + eq->numJugadores[3];
    for (int j = 0; j < jcant; ++j)
    { // por cada jugador
        Jugador player = eq->jugadores[j];
        printf("\t%d)\tNombre: %s\n", j + 1, player.nombre); // imprimimo el valor de su atributo nombre
        printf("\t\tPosicion: %s\n", player.posicion);       // imprimimo el valor de su atributo posicion
        printf("\t\tEdad: %u\n", player.edad);               // imprimimo el valor de su atributo edad
        printf("\t\tRegate: %f\n", player.regate);           // imprimimo el valor de su atributo regate
        printf("\t\tDefensa: %f\n", player.defensa);         // imprimimo el valor de su atributo defensa
        printf("\t\tReflejos: %f\n", player.reflejos);       // imprimimo el valor de su atributo reflejos
        printf("\t\tVelocidad: %f\n", player.velocidad);     // imprimimo el valor de su atributo velocidad
        printf("\t\tDureza: %f\n", player.dureza);           // imprimimo el valor de su atributo dureza
        printf("\t\tResistencia: %f\n", player.resistencia); // imprimimo el valor de su atributo resistencia
        printf("\n");
    }
    printf("\n");
}
//Funcion que imprimime toda la informacion de los miembros del staff
void ImprimirStaff(Equipo *eq)
{ // Calculamos el total de miembros que hay en el staff del equipo
    int staffCant = eq->numStaff[0] + eq->numStaff[1] + eq->numStaff[2] + eq->numStaff[3] + eq->numStaff[4] + eq->numStaff[5];
    for (int j = 0; j < staffCant; ++j)
    { // Por cada staff en el equipo
        Staff staff = eq->staff[j];
        printf("\t%d)\tNombre: %s\n", j + 1, staff.nombre);  // imprimimo el valor de su atributo nombre
        printf("\t\tEdad: %u\n", staff.edad);                // imprimimo el valor de su atributo edad
        printf("\t\tRol: %s\n", staff.rol);                  // imprimimo el valor de su atributo rol
        printf("\t\tExperiencia: %u\n", staff.experriencia); // imprimimo el valor de su atributo experiencia
    }
}
// funcion que imprime toda la informacion de la fanaticos de un equipo
void ImprimirFanaticos(Equipo *eq)
{ // por cada una de los fanaticos de un equipo
    for (int j = 0; j < eq->numFanaticos; j++)
    {
        Fanatico fan = eq->fanaticos[j];
        printf("\t%d)\tNombre: %s\n", j + 1, fan.nombre);  // imprimimo el valor de si atributo nombre
        printf("\t\tEdad: %u\n", fan.edad);                // imprimimo el valor de si atributo edad
        printf("\t\tAgresividad: %lf\n", fan.agresividad); // imprimimo el valor de si atributo agresividad
    }
}
// funcion que imprime toda la informacion de una base de datos
void ImprimirDB(Equipo *eq, int *numEquipos)
{
    for (int i = 0; i < *numEquipos; ++i)
    { // por cada unan de los equipos en la base de datos
        Equipo team = eq[i];
        printf("-------------------------------------------------------------------------------\n");
        printf("\t\t\tMiembros del Equipo %s\n", team.nombre); // imprimimos el nombre del equipo
        printf("-------------------------------------------------------------------------------\n");
        printf("\t\t\t\tAño de Fundacion: %d\n", team.anyoFundacion); // imprimimos el anyo de fundacion del equipo
        printf("\n");
        printf("\tJugadores: \n");
        printf("\n");
        ImprimirJugadores(&team); // imprimimos los datos de los jugadores del equipo
        printf("\n");
        printf("\tStaff:\n");
        printf("\n");
        ImprimirStaff(&team); // imprimimos los datos de los miembros del staff del equipo
        printf("\n");
        printf("\tFans:\n");
        printf("\n");
        ImprimirFanaticos(&team); // finalmente imprimimos los datos de los fanaticos del equipo
        printf("\n");
    }
}