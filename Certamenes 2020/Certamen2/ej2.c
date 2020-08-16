#include <stdio.h>
#include <stdlib.h>

int DistanciaEntreDosPuntos(int *p1, int *p2) //funcion que calcula la distancia entre dos posiciones en una matriz
{
    int distancia = abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]);
    return distancia;
}

int main()
{
    int n, m;                   // variables para guardar valores entregados por teclado
    scanf("%d%d", &n, &m);      // leemos el orden de la matriz y la cantidad de posiciones que seran entregados
    int matriz[n][n];           // declaramos nuestra matriz
    int coord[m][2];            // declaramos nuestro arreglo de coordenadas
    for (int i = 0; i < n; i++) // pedimos los valores por cada posicion en nuesta matriz
        for (int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    for (int i = 0; i < m; i++) // luego pedimos  las posciones del camino en orden
        scanf("%d%d", &coord[i][0], &coord[i][1]);

    for (int i = 0; i < m; i++) // por cada posicion entregado
    {
        if (matriz[coord[i][0]][coord[i][1]] == 1) // verificamos que este libre
        {
            printf("Incorrecto\n"); // de estar ocupoda es un camino incorrecto
            return 0;               // y se termina el programa
        }
        else if (i != m - 1 && DistanciaEntreDosPuntos(coord[i], coord[i + 1]) != 1) // si la posicion esta libre, chequemamos que la distancia a la sigueite posicion entregada sea uno, al meno que sea la ultima posicion entregada
        {
            printf("Incorrecto\n"); // de no tener distancia 1 con el siguiente punto entregado es un camino incorrecto
            return 0;               // y el programa se termina
        }
    }
    printf("Correcto\n"); // si todos los puntas pasan por las condiciones anteriores el camino es correcto
    return 0;
}