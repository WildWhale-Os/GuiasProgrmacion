/*
Problema:
Escriba un programa que pida un numero entero e imprima
todos sus divisores entre el 2 y el 10(no usar ciclos).
*/

#include <stdio.h>

//solucion mas sencilla pero la menos optima.
/* int main(void)
{

    int numero = 0;
    printf("Ingrese un numero entero: ");
    scanf("%i", &numero);

    printf("El numero %i es divisible por: \n", numero);
    if (numero % 2 == 0)
    {
        printf("- 2\n");
    }
    if (numero % 3 == 0)
    {
        printf("- 3\n");
    }
    if (numero % 4 == 0)
    {
        printf("- 4\n");
    }
    if (numero % 5 == 0)
    {
        printf("- 5\n");
    }
    if (numero % 6 == 0)
    {
        printf("- 6\n");
    }
    if (numero % 7 == 0)
    {
        printf("- 7\n");
    }
    if (numero % 8 == 0)
    {
        printf("- 8\n");
    }
    if (numero % 9 == 0)
    {
        printf("- 9\n");
    }
    if (numero % 10 == 0)
    {
        printf("- 10\n");
    }

    return 0;
} */

//solucion optima dentro de las posibilidades(sin loop).
void divisor(int n, int d)
/* Funcion que busca e imprimer en pantalla los divisiores de un numero, n es el numero al que se le buscaran 
los divisores, y d es el primer numero desde el cual se buscaran los divisores del numero d*/
{
    if (n < 2 && n > -2) // el numero entregador debe vivir en [-2,2] de otro forma no tendra divisores entre 2 y 10.
    {
        printf("El numero entregado no tiene divisiores entre 2 y 10.\n");
    }
    else if (d <= 10) // Solo buscara divisiores entre el numero d entregado hasta el 10.
    {
        if (n % d == 0) // cheackea que el numero entregado por teclado sea divisible por numero d entrgado.
        {
            printf("- %i\n", d);// si n es divisible en d se imprimira el valor de d en pantalla.
        }
        divisor(n, ++d);// se ejecuta de nuevo la funcion pero con el succesor de d
    }
}

int main()
{
    
    int numero;
    printf("digite un numero entero: ");
    scanf("%i", &numero);// Lectura de datos entrgados por teclado

    divisor(numero, 2);// se llama a la funcion divisor entregandole en numero entregado por teclado y el 2.

    return 0;
}