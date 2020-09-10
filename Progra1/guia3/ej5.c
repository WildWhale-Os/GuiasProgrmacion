/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que pida un número entero y un caracter e imprima: 
contenido en caso de que el 8 bits codificando caracter se corresponda 
con alguno de los 4Bytes que constituyen el número entero. En caso contrario, 
imprimir el número entero que se formaría al concatenar los bits correspondientes al caracter cuatro veces.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;                                            // declaramos la variable que contendra el numero entero que se nos sera entregado
    char letra;                                         // declaramos la variable que contendra el caracter que se nos sera entregado
    int bytes[4];                                       // declaracion del arreglo en donde guarda remos cada una de los bytes que compone al entero que nos entregan
    printf("Ingrese un numero entero y un caracter: "); // pedimos que nos entreguen un numero y un caracter
    scanf("%d %c", &num, &letra);                       // leemos y guardamos el numero y el caracter, en su repectiva variable deeclarada anteriormente
    printf("Numero: %d y letra: %c\n", num, letra);     // imprimimos cuales son los datos guardados a modo de verificacion

    bytes[0] = num >> 24; // aislamos el byte de mas a la izquerda que compone al entero entregado

    bytes[1] = (num << 8) >> 24;  // aislamos el segundo bayte de izquerda a derecha
    bytes[2] = (num << 16) >> 24; // ailsamos el tercer byte de izqueda a derecha
    bytes[3] = (num << 24) >> 24; // aislamos el bayte de mas a la derecha

    for (int i = 0; i < 4; i++) // por cada una de los bytes que componen al entero que se nos a entregado
    {
        if ((letra | bytes[i]) == bytes[i]) // verificamos que si al hacer la operacion and bit a bit con los 8 bits del caracter que se nos a entregado sea igual a alguno de los bytes que componen el entero que se nos a entregado
        {
            printf("contenido.\n"); // de ser asi imprimimos contenido
            return 0;               // y terminamos el programa
        }
    }

    printf("Los 8 bits del caracter entregado concatenado 4 veces es igual al numero %d.\n", (int)letra | (int)letra << 8 | (int)letra << 16 | (int)letra << 24); // de no ser asi imprimimos el entero que corresponde a concatenar 4 veces el byte que forman el caracter que se nos a entregado

    return 0;
}