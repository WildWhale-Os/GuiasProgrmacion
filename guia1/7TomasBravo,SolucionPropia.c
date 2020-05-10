/*
Problema:
Escribe un programa que pida un número entero entre 1 y 10 e imprima "paranguacutilimicuaro"
esa cantidad de veces. En caso de que el número ingresado se encuentre fuera de rango, 
el programa deberá terminar. (No usar ciclos)
*/
#include <stdio.h>

void Imprimir(int rep, int init) 
/* funcion que imprimira "paranguacutilimicuaro", rep que es el numero entregado por teclado es cantidad de veces que se imprimira la palabra
, y init que es la cantidad e veces se han impreso la palabra, es una variable de control*/
{
    if (rep > 10 || rep < 1) // si el numero entragdo no vive en [1,10]
    {
        printf("El numero entregado no esta en el rango de 1 a 10\n"); // se imprimer en pantalla ""El numero entregado no esta en el rango de 1 a 10"
    }
    else // si el numero vive en [1,10]
    {
        if (init <= rep) // si numero de veces que se han impreso la palabra es menor o igual al numero de veces que se debe imprimir
        {
            printf("%i) paranguacutilimicuaro\n", init); // imprirmir "paranguacutilimicuaro"
            Imprimir(rep, ++init); // vuelve a ejecutar esta funcion, aumentando en 1 el valor de la variable de control.
        }
    }
}

int main(void)
{
    
    int numero;
    printf("Digite un numero entre 1 y 10: ");
    scanf("%i", &numero); // Lectura de datos entrgados por teclado

    Imprimir(numero, 1); // ejecutar la funcion que imprime "paranguacutilimicuaro", "numero" de veces, partiendo desde la 1.
    /* switch (numero)
    {
    case 10:
        printf("- paranguacutilimicuaro\n");

    case 9:
        printf("- paranguacutilimicuaro\n");

    case 8:
        printf("- paranguacutilimicuaro\n");

    case 7:
        printf("- paranguacutilimicuaro\n");

    case 6:
        printf("- paranguacutilimicuaro\n");

    case 5:
        printf("- paranguacutilimicuaro\n");

    case 4:
        printf("- paranguacutilimicuaro\n");

    case 3:
        printf("- paranguacutilimicuaro\n");

    case 2:
        printf("- paranguacutilimicuaro\n");

    case 1:
        printf("- paranguacutilimicuaro\n");
        break;
    default:
    {
        printf("El numero digitado es invalido\n");
        break;
    }
    }
 */
    return 0;
}