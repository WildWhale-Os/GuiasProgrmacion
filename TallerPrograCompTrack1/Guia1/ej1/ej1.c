#include <stdio.h>
#include <stdlib.h>

int algoritm(int num)
{
    int it = 1;
    while (num != 1)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            num = 3 * num + 1;
        it++;
    }
    return it;
}

int BiggestIteracion(int num1, int num2)
{
    int mayor = -1, iteraciones;
    for(int i = num1; i <= num2; i++)
    {
        iteraciones = algoritm(i);
        if (iteraciones > mayor)
            mayor = iteraciones;
    }

    return mayor;
}

int main(int argc, char const *argv[])
{
    int num1, num2, resultado;
    while (scanf("%d%d", &num1, &num2) != EOF)
    {
        resultado = num1 > num2 ? BiggestIteracion(num2, num1) : BiggestIteracion(num1, num2);
        printf("%d %d %d\n", num1, num2, resultado);
    }

    return 0;
}
