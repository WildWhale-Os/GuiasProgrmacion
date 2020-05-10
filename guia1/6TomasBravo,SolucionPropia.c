/*
Problema:
Escribe un programa que pida 3 números enteros e imprima "variadito" si, o bien, exáctamente
dos de ellos son pares o dos son impares. En caso contrario imprimir "uniforme".
*/
#include <stdio.h>

int main(void)
{

    int numero1, numero2, numero3, pares = 0;

    printf("Digite 3 numeros enteros: ");
    scanf("%i %i %i", &numero1, &numero2, &numero3); // Lectura de datos entrgados por teclado

    if (numero1 % 2 == 0) // si numero1 es par
        pares++; // suma 1 al valor de pares
    

    if (numero2 % 2 == 0) // si numero2 es par
        pares++; // suma 1 al valor de pares
    

    if (numero3 % 2 == 0) // si numero3 es par
        pares++; // suma 1 al valor de pares
    

    switch (pares)
    {
    case 0:
        printf("uniforme\n"); //  si no hay numeros pares entre los tres numero entregados imprimir en pantalla "uniforme"
        break;
    case 1:
        printf("variadito\n"); // si hay un numero par entre los tres numero entregados imprimir en pantalla "variadito"
        break;
    case 2:
        printf("variadito\n"); // si hay dos numeros pares entre los tres numero entregados imprimir en pantalla "variadito"
        break;
    case 3:
        printf("uniforme\n"); // si los tres numeros entregados son pares imprimir en pantalla "uniforme"
        break;
    }

    return 0;
}
