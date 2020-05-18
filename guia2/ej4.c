/*

Autor: Tomas Bravo
Solucion Propia.

Problema 4:
Escribe un programa que pida un número entero y escriba 
primo o compuesto según sea el caso.

*/
#include <stdio.h>

int main()
{

    int numero;
    int primo = 0;
    printf("Digite un numero entero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
    {
        if (numero != 1)
            if (numero % i == 0)
                if (i == 1 || i == numero)
                    primo++;
                else
                    primo--;
    }

    if (primo == 2)
        printf("El numero ingresado es Primo\n");
    else
        printf("El numero ingresado es Compuesto\n");

    return 0;
}