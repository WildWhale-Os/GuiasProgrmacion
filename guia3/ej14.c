/*
Autor: Tomas Bravo
Tipo de Solucion: Propia
timus_ID = TomasBravo
Judge_ID = 295450ZH
https://acm.timus.ru/problem.aspx?space=1&num=1585
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, emp = 0, lp = 0, mcp = 0; // declaramos los contadores de cada tipo de pinguino
    char penguin[30];                  // declaramos el string donde guardaremos el nombre del pinguino que sera ingresado
    scanf("%d", &num);                 // pedimos la cantidad de nombres que seran ingresados
    getchar();                         // limpiamos el buffer del teclado
    for (int i = 0; i < num; i++)      // pedimos n nombres
    {
        scanf("%[^\n]s", penguin);                    // leemos el nombre ingresado y lo guardamos
        getchar();                                    //limpiamos el buffer del teclado
        if (strcmp(penguin, "Emperor Penguin") == 0)  // si coincide con el nombre de esta especie pinguino
            emp += 1;                                 // aumentamos su contador en 1
        if (strcmp(penguin, "Little Penguin") == 0)   // si coincide con esta especie  de pinguino
            lp += 1;                                  // aumentamos su contador en 1
        if (strcmp(penguin, "Macaroni Penguin") == 0) // o si finalmente coincide con el nombre de esta otra especie de pinguino
            mcp += 1;                                 // aumentamos su contador en 1
    }

    if (emp > lp && emp > mcp) // finalmete imprimimos la especie de pinguinos que mas veces fue ingresada.
        printf("Emperor Penguin\n");
    else if (lp > emp && lp > mcp)
        printf("Little Penguin\n");
    else
        printf("Macaroni Penguin\n");

    return 0;
}