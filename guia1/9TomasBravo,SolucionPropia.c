/*
Problema:
Resolver el problema "Two Gangsters" en la plataforma Timus. 
Recuerda subir el código y el pantallazo de su código aceptado por la plataforma.
https://acm.timus.ru/problem.aspx?space=1&num=1409
*/
#include <stdio.h>

int main(void)
{
    // Lectura de datos entrgados por teclado
    int harry, larry, notHarry, notLarry;
    scanf("%d %d", &harry, &larry);

    notHarry = larry - 1;
    notLarry = harry - 1;

    printf("%d %d\n", notHarry, notLarry);

    return 0;
}

// Entregar a Juez virtuel link en la parte superior