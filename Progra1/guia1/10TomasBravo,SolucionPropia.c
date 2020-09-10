/*
Problema:
Resolver el problema "Lost in Localization" en la plataforma Timus. 
Recuerda subir el código y el pantallazo de su código aceptado por la plataforma.
https://acm.timus.ru/problem.aspx?space=1&num=1785
*/
#include <stdio.h>

int main(void)
{
    
    int n;
    scanf("%i", &n);// Lectura de datos entrgados por teclado

    if (1 <= n && n <= 2000) // si el numero entrgado vive en [1,2000]
    {
        if (1 <= n && n <= 4) //si el numero entregado vive en [1,4]
        {
            printf("few\n"); // imrpimir en pantalla "few"
        }
        else if (5 <= n && n <= 9) //si el numero entregado vive en [5,9]
        {
            printf("several\n"); // imrpimir en pantalla "several"
        }
        else if (10 <= n && n <= 19) //si el numero entregado vive en [10,19]
        {
            printf("pack\n"); // imrpimir en pantalla "pack"
        }
        else if (20 <= n && n <= 49) //si el numero entregado vive en [20,49]
        {
            printf("lots\n"); // imrpimir en pantalla "lots"
        }
        else if (50 <= n && n <= 99) //si el numero entregado vive en [50,99]
        {
            printf("horde\n"); // imrpimir en pantalla "horde"
        }
        else if (100 <= n && n <= 249) //si el numero entregado vive en [100,249]
        {
            printf("throng\n"); // imrpimir en pantalla "throng"
        }
        else if (250 <= n && n <= 499) //si el numero entregado vive en [250,499]
        {
            printf("swarm\n"); // imrpimir en pantalla "swarm"
        }
        else if (500 <= n && n <= 999) //si el numero entregado vive en [500,999]
        {
            printf("zounds\n"); // imrpimir en pantalla "zounds"
        }
        else if (1000 <= n) //si el numero entregado es mayor o igual a 1000
        {
            printf("legion\n"); // imrpimir en pantalla "legion"
        }
    }

    return 0;
}