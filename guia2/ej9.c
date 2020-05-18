/* 

Autor: Tomas Bravo
Solucion Propia.

Problema 9:
Escribe un programa que pida un número entero n y a continuación 
lea n coordenadas en dos dimensiones. El programa deberá imprimir 
por pantalla las coordenadas del punto medio de la región cuadrada 
delimitada por: el punto con la abscisa de menor valor, el punto con 
la abscisa de mayor valor, el punto con la ordenada de mayor valor y 
el punto con la ordenada de menor valor.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amountVectors, coX, coY;                                // declaramos las variables para almecenar cuantos vectores van a ser introducidos y las variables para almacenar y precesar las variables x e y de cada vector.
    int mayorX[2], menorX[2], mayorY[2], menorY[2], central[2]; //declaramos los vectores que contendran los vectores conformaran el plano, y por ultimo el vector que que estara en el centro del plano formado

    do // se le pide al usuario que entregue la cantidad de vectores que seran entregados al programa para procesar
    {
        printf("Cuantos vectores seran entregados (n > 0): ");
        scanf("%d", &amountVectors);

    } while (amountVectors < 0); // si la cantidad entregada en menor a o se le pediara otro numero

    if (amountVectors > 0)
    {
        for (int i = 0; i < amountVectors; i++) // se le pediran las coordenadas X e Y de los amountVectors que el usuario dijo que entregaria
        {
            printf("entregue las coordenas de el vector %d de la forma (x,y): ", i + 1);
            scanf("%d %d", &coX, &coY); // se lee y almacenan las coordenadas de cada vector

            if (i == 0) // en la primera iteracion
            {           // se iguala cada vector que compondra el plana al primer vector entregado para tener un marco de referencia
                mayorX[0] = coX;
                mayorX[1] = coY;
                mayorY[0] = coX;
                mayorY[1] = coY;
                menorX[0] = coX;
                menorX[1] = coY;
                menorY[0] = coX;
                menorY[1] = coY;
            }
            else // en el resto de la iteraciones
            {
                if (coX > mayorX[0]) // se verifica si la coordenada X del vector entregada es mayor a la coordenada X mas grande de los vectores entregados
                {                    // de ser asi que cambia todo el vector que contiene al vector con la abscisa mas grande por el vector recien entregado
                    mayorX[0] = coX;
                    mayorX[1] = coY;
                }

                if (coX < menorX[0]) // se verifica si la coordena X entregada en menor que la abscisa menor almacenada
                {                    // de ser asi se cambia el vector que contiene la abscisa menor de todos los vectores entregados por el vector recien entregado
                    menorX[0] = coX;
                    menorX[1] = coY;
                }

                if (coY > mayorY[1]) // si la odenada del vector recien entegado es mayor a la ordenada mas grande almacenada
                {                    // se cambia el valor del vector almacenado por el vector recien entegado
                    mayorY[0] = coX;
                    mayorY[1] = coY;
                }

                if (coY < menorY[1]) // si la ordenada del vector recien entregado es menor a la menor ordenada almacenada
                {                    // se cambia el valor del vector que estaba almacena por el vector reciene entregado
                    menorY[0] = coX;
                    menorY[1] = coY;
                }
            }
        }

        //calculamos el punto central entre los cuatro puntos
        central[0] = (mayorX[0] + menorX[0] + mayorY[0] + menorY[0]) / 4;
        central[1] = (mayorX[1] + menorX[1] + mayorY[1] + menorY[1]) / 4;

        //imprimimos el resultado en pantalla
        printf("El punto central del plano formado por los puntos (%d, %d), (%d, %d), (%d, %d) y (%d, %d) es : (%d, %d)\n", mayorX[0], mayorX[1], menorX[0], menorX[1], mayorY[0], mayorY[1], menorY[0], menorY[1], central[0], central[1]);
    }
    return 0;
}