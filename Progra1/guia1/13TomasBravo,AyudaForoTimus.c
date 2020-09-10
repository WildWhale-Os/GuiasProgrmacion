/*
Problema:
Resolver el problema "Ural Steaks en la plataforma Timus. 
Recuerda subir el código y el pantallazo de su código aceptado por la plataforma.
https://acm.timus.ru/problem.aspx?space=1&num=1820

Preguntar por dos numeros en una sola linea 
numero de steaks, numero de staek que caben en un
solo sarten.


*/
#include <stdio.h>

int main(void)
{
    
    int n, k; // n es el numero de filetes a cocinar y k es la cantidad de filetes que se puedes cocinar al mismo tiempo (capacidad del sarten)
    scanf("%d %d", &n, &k); // Lectura de datos entrgados por teclado

    if (n <= k) // si el numero de filetes a cocinar es menor o igual al numero de filetos que se pueden cocinar al mismo tiempo
    {
        printf("2"); // el cocinera se demorara 2 minutos en cocinar todos los filetes
    }
    else if (2 * n % k == 0) 
    /* si el numero de filetes a cocinar es mayor que la capacidad maxima del sarten, y el doble de filetes a cocinar es divisible
    por la capacidad del sarten */
    {
        printf("%i\n", (2 * n / k)); // el cocinero de demorara 2 min por cada grupo de k filetes que se pueden hacer de los n filetes que se tienen que cocinar.
    }
    else
    /* si el numero de filetes a cocinar es mayor que la capacidad maxima del sarten, y el doble de filetes a cocinar no es divisible
    por la capacidad del sarten */
    {
        printf("%i\n", (2 * n / k) + 1);
        /* el cocinero de demorara 2 min por cada grupo de k filetes que se pueden hacer de los n filetes que se tienen que cocinar
         mas un minuto, ya que la cantidad de filetes que quedan por cocinar despues de haber cocido todos los grupo de k filetes
         que se pueden hacer de n filetes, se terminan cocinar en ese minuto extra*/
    }

    return 0;
}