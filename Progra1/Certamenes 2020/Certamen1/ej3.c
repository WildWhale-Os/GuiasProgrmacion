#include <stdio.h>
#include <stdlib.h>

int main()
{
    int carton[3][9], validos = 0; // declaramos nuestro carton donde estaran nuestros numeros del bingo, validos una variable que llevara la cuanta de cuantos numeros son validos dentro del carton
    printf("Entregue los numeros en el carton que quiere ser verificado en forma de matriz de 3x9: \n");
    for (int i = 0; i < 3; ++i)     // por cada fila
        for (int j = 0; j < 9; ++j) // por cada columna de cada fila
        {
            scanf("%d", &carton[i][j]);                                        // llenamos nuestro carton en cada posicion
            if ((carton[i][j] > 90 || carton[i][j] < 1) && carton[i][j] != -1) // verificamos que los numeros pertenescan al conjunto [1,90] o que sean -1
            {
                printf("Este carton de bingo es defectuoso\n"); // de otra forma es una carton defectuoso
                return 0;                                       // por lo que terminamos el programa
            }
        }

    for (int i = 0; i < 3; ++i) // por cada fila
    {
        for (int j = 0; j < 9; ++j) // por cada columnad de cada fila
        {
            if (carton[i][j] != -1) // verificamos que no sean -1
            {
                for (int r = 0; r < 3; ++r) // si son != -1 , los comparemos
                {
                    for (int t = 0; t < 9; ++t) // con los demas numero de la matriz
                    {
                        if (i != r || j != t) // pero con el mismo
                        {
                            if (carton[i][j] == carton[r][t]) // si otro numero dentro del carton es igual a el
                            {
                                printf("Este carton de bingo es defectuoso\n"); // el carton es defectuoso
                                return 0;                                       // se termina el programa
                            }
                        }
                    }
                }

                validos++; // si no hay numero iguales al actual agregamos uno a la cuenta de los numero validos
            }
        }
    }

    if (validos == 15)                                  // si los numeros validos son 15 y no hay numero repetidos
        printf("Este carton de bingo esta correcto\n"); // el carton esta correcto

    else                                                // si los numeros validos son != 15
        printf("Este carton de bingo es defectuoso\n"); // el carton es defectuoso

    return 0;
}