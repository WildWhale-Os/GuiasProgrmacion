/*
Problema:
Escribe un programa que pida 3 números enteros e imprima: al menos uno, si al menos 
uno es negativo; al menos dos, si al menos dos lo son; todos, si los tres son negativos 
o; ninguno, si todos son positivos.
*/
#include <stdio.h>

int NumerosNegativos(int numero1, int numero2, int numero3)// funcion que entrega cuantos numeros negativos hay entre los numero entregados como argumentos.
{
    int negativos = 0;

    if (numero1 < 0) // si valor de numero1 es menor a 0, se le sumara 1 al valor de negativos.
    {
        negativos++;
    }

    if (numero2 < 0)// si valor de numero2 es menor a 0, se le sumara 1 al valor de negativos
    {
        negativos++;
    }
    if (numero3 < 0) // si valor de numero3 es menor a 0, se le sumara 1 al valor de negativos.
    {
        negativos++;
    }

    return negativos; // devuelve el numero de negativos habia entre los tres enteros entregados.
}

int main(void)
{
    
    int numero1, numero2, numero3, negativos;
    printf("Digite 3 numeros enteros: ");
    scanf("%d %d %d", &numero1, &numero2, &numero3);// Lectura de datos entrgados por teclado.

    negativos = NumerosNegativos(numero1, numero2, numero3);// cantidad de numeros negativos entre los numero entregados por teclado.

    switch (negativos) 
    {
    case 0:
        printf("ninguno\n"); // si no hay negativos se imprime en pantalla "ninguno".
        break;
    case 1:
        printf("al menos uno\n");// si hay un negativo se imprime en pantalla "al menos uno".
        break;
    case 2:
        printf("al menos dos\n");// si hay dos negativos se imprime en pantalla "al menos dos".
        break;
    case 3:
        printf("todos\n");// si todos son negativos se imprime en pantalla "todos".
        break;
    }

    return 0;
}
