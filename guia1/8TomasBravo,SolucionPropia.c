/*
Problema:
Resolver el problema "Eniya" en la plataforma Timus. 
Recuerda subir el código y el pantallazo de su código aceptado por la plataforma.
https://acm.timus.ru/problem.aspx?space=1&num=1293
*/
#include <stdio.h>

int main(void)
{
   
    int N, A, B, resultado;
    scanf("%d %d %d", &N, &A, &B); // Lectura de datos entrgados por teclado

    if ((N, A, B) >= 1 && (N, A, B) <= 100) // si los tres valores entregados viven en [1,100]
    {
        resultado = (N * (A * B)) * 2; // se multiplican los dos ultimos valores entregados, el producto se multiplica por el primer numero entregado, y este porducto final se multiplica por 2.

        printf("%d\n", resultado); // se imprime el producto de toda la operacion anterior.
    }

    return 0;
}

// Entregar a Juez virtuel link en la parte superior