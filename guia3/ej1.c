/*

Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que, dado un número entero entre 0 y 255, imprima su representación como:
- Caracter.
- Entero sin signo.
- Número octal.
- Número hexadecimal.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // arreglo para imprimir la representacion en hexadecimal
    int num;                                                                                       // declaramos una variable donde guardaramos el numero que se nos era entregado
    printf("Digite un numero entre el 0 y el 255: ");                                              // pedimos el numero al usuario
    scanf("%d", &num);                                                                             // guardamos el numero en la variable declarada anteriormente
    while (num < 0 || num > 255)                                                                   // si el numero no vive en [0,255]
    {
        printf("El numero digitado no pertenece [0,255], ingrese otro numero: "); // se pedira que ingrese otro numero al usuario
        scanf("%d", &num);                                                        // y se guardara dentro de la misma variable
    }
    printf("-------------------------------------------------------------\n");
    //imprimir caracter
    printf("EL caracter representado en la tabla ASCII por el numero entregado es %c. \n", (char)num); // imprimimos el caracter al que corresponder el codigo ascii = al numero entregado
    //imprimir entero sin signo
    printf("El numero entero si signo respresentado por el numero ingresa es el %u.\n", num); // imprimimos el numero sin signo correspondiente al numero entregado
    //imprimir octal
    //printf("El numero entregado respresentado de forma Octal es %d%d%d.\n", (num / 64), (num % 64) / 8, (num % 64) % 8);
    printf("El numero entregado respresentado de forma Octal es %o.\n", num); // imprimimos el numero entregado en su respresentacion de base 8
    //Imprimir hexadecimal
    // printf("El numero entregado respresentado de forma Hexadecimal es %c%c.\n", hex[num / 16], hex[num % 16]);
    printf("El numero entregado respresentado de forma Hexadecimal es %X.\n", num); // imprimimos el numero ingresado en su representacion de base 16

    return 0;
}