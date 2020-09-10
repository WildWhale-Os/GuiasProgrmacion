/*
Autor: Tomas Bravo
Tipo de Solucion: Propia
timus_ID = TomasBravo
Judge_ID = 295450ZH
https://acm.timus.ru/problem.aspx?space=1&num=2100
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, price = 200; //Declaramos la variable num donde guardamos el numero de invitados a la boda, y el precio de la boda que es de 200 inicialmente por que solo son la pareja que se va a casar de forma inicial los que asistiran a la boda si o si
    char name[20];        // luego delcaramos una cadena de caracteres donde guardaremos los nombres que nos ingresen

    scanf("%d", &num);         // leemos y guardamos la cantidad de invitados que hay a la boda
    getchar();                 // limpiamos el buffer del teclado
    if (num >= 1 && num <= 20) // verificamos que el numero ingresado este en el rango entregrado por el problema
    {
        for (int i = 0; i < num; i++) // pedimos num cantidad de nombres
        {
            scanf("%s", name);                // leemos cada nombre individualmente
            getchar();                        // volvemos a limpiar el buffer del teclado
            price += 100;                     // agragamos 100 al precio de la boda por cada invitado que a confirmado
            if (strstr(name, "+one") != NULL) // si dentro de la cadena del nombre del invitado se encuntra la cadena de caracteres "+one" significa que el invitado tiene con pareja
                price += 100;                 // por lo que sumamos otros 100 al precio de la boda
        }

        if (price == 1300)     // como el esposo es supersticioso, si la cantidad de asistentes es justo 13
            price += 100;      // se pedira que se agregue un puesto mas con un dummy, por lo que son 100 mas al precio de la boda
        printf("%d\n", price); // imprimimos el precio total de la boda
    }
    return 0;
}