/*
 
 Autor: Tomas Bravo
Solucion 

timus_ID = TomasBravo
Judge_ID = 295450ZH

Problema 16:
Timus 1910 Titan Ruins: Hidden Entrance


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sections, good = 1, posEntrada, absForce = 0; //definimos la variable donde guardaremos en numero de secciones que tiene la pared
    scanf("%d", &sections);                                               // leemos y guardamos ese numero entregado por el usuario
    if (sections >= 3 && sections <= 1000)                                // si el numero vive en 3 <= n <= 1000
    {
        int magicForce[sections];          // definimos el arreglo que contendra las niveles de fuerza magica en cada seccion
        for (int i = 0; i < sections; i++) // iteramos por el array
        {
            scanf("%d", &magicForce[i]);                      // y leemos los valores de fuerza magica que son entregados por el usuario
            if (magicForce[i] < 1 || magicForce[i] > 1000000) // de ser un valor que no vive en 1<= n <= 10^6 se saldra del programa
            {
                good = 0;
                break;
            }
        }

        if (good == 1) // los valores entregados cumplen con todas las condiciones dadas
        {
            for (int i = 0; i <= sections - 3; i++)// se recorre cada valor de fuerxa magica de cada section
            {
                if (i == 0) // en la primer iteracion 
                {
                    absForce = magicForce[0] + magicForce[1] + magicForce[2]; //la fuerza conjunta sera la de los tres primeros valores juntos
                    posEntrada = 2; // y la poscision de la entreada sera la del segundo valor de fuerza
                }

                else if (absForce < magicForce[i] + magicForce[i + 1] + magicForce[i + 2]) // despues se comparar el valor de fuerza conjunta sumando de a tres valores consecutivos
                {
                    absForce = magicForce[i] + magicForce[i + 1] + magicForce[i + 2]; // si uno es mayor que la fuerza conjunta anterior se cambia el valor de esta variable
                    posEntrada = i + 2; //junto con la posicion de la entrada a las ruinas.
                }
            }

            printf("%d %d\n", absForce, posEntrada); // finalmente se imprimen los resultados.
        }
    }

    return 0;
}