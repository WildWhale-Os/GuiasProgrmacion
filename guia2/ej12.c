/* 
Autor: Tomas Bravo
Solucion Propia.

timus_ID = TomasBravo
Judge_ID = 295450ZH

Problema 12:
Timus 1787. Turn for MEGA


*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, autosRestantes = 0, good = 1, carsAtTime; // declaramos las variables necesarias para nuestro porblema

    scanf("%d %d", &k, &n); // pedimos al usuario la taza de autos que sales de la curva en un minuto y la cantidad de minutos que han pasado desde el inicio de la observacion

    if (k >= 1 && n <= 100)
    {
        for (int i = 1; i <= n; i++) // ahora por cada minuto pasado desde el inicio de la observacion
        {
            scanf("%d", &carsAtTime); // le pediremos al usuario que ingrese un numero que son las autos que vienen desde la cuidad hacia la curva en cada minuto de observacion partiendo desde el 1 en minuto 0 habian cero autos en la curva
            if (carsAtTime >= 0 && carsAtTime <= 100)
            {
                autosRestantes += (carsAtTime - k); //a la cantidad inicial de autos en la cruva se le sumara la resta entre la cantidad de autos que vienen desde la cuidad y la taza con la que los autos salen del atasco
                if (autosRestantes < 0)             // si la cantidad de autos que quedan en el atasco llegara a ser negativa
                    autosRestantes = 0;             // pasamos ese numero negativo a cero ya que no puede haber un numero negativo de autos en un cruze
            }
            else
                good = 0;
        }

        if (good)
            printf("%d\n", autosRestantes); // finalmente si todos los valores entregados cumplen con todas las condiciones dadas en el enunciado se imprimera el numero de autos que todavia estan en el atasco.
    }
    return 0;
}