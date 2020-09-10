#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dif, num[5]; //declaracion variable que se guardara la diferencia mayor y el arreglo que contendra los numeros entregados
    printf("Ingrese 5 numeros a procesar, en una sola linea, separados cada uno con un espacio:\n");
    for (int i = 0; i < 5; ++i) // se leen los numeros y se guardan
        scanf("%d", &num[i]);

    for (int i = 0; i < 5; i++) // por cada numero entregado
    {
        for (int j = 0; j < 5; j++) // se compara con todos los demas numero incluyendo con si mismo
        {
            if (i == 0 && j == 0) // si es el primero numero inicializamos el valor de dif con la resta de el pimero numero entregado restado con el mismo numero, en otras palabras dif = 0
                dif = num[0] - num[0];
            else if (dif < num[i] - num[j]) // para el resto de las comparaciones se compara las resta de los distintas parejas de numeros con dif
                dif = num[i] - num[j];      // si la diferencia entre la pareja de los numeros actuales es mayor a dif se cambia el valor de dif al valor de la diferencia
        }
    }

    printf("%d\n", dif); // finalmente imprimmos el valor de dif en pantalla

    return 0;
}