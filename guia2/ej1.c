/* 

Autor: Tomas Bravo 
con ayuda de video de youtube.

Material de Apoyo:
https://www.youtube.com/watch?v=0iYLgzr2tpg

Problema 1 :
Escribe un programa que pida un numero entero n y a continuacion imprima
los n primeros numeros de la sucesion de fibonacci. El programa debe validar
que numero ingresado sea positivo.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;        //variable donde se almacenara el numero pedido al usuario
    int a = 0;         // primer variable de apoyo
    int b = 1;         // segunda variable de apoyo
    int resultado = 0; // variable en donde se almacena el numero que sera impreso

    do
    { // verificacion de que el numero entregado sea positivo de otro forma pedir otro valor
        printf("ingrese un numero entero mayor a cero: ");
        scanf("%d", &numero); // inicializar valor de numero
    } while (numero <= 0);

    printf("Los primeros %d numeros de la serie de Fibonacci son: \n",numero );

    for (int control = 0; control <= numero; control++) // bucle que imprime los numero de la serie Fibonacci
    {
        printf("%d) %d\n", control + 1, resultado); // imprimir el valor de resultado al inicio del bucle(0 en la primera iteracion)
        a = b;
        b = resultado;
        resultado = a + b;
        /* como los primeros valores de la serie de Fibonacci son el 0 y 1, es por eso que se inicializan
        ambas variables auxiliares como 0 y 1 respectivamente, ya que despues de que al inciar el bucle por
        primera vez inmediatemente se imprimira 0 que es el valor inicial de la variable resultado y el primer
        valor de la serie de Fibonacci despues de haber impreso el resultado, cambiame el valor de la variable a = 0
        por  a = b = 1 y cambiamos el valor de la variable b = 1 a b = resultado = 0, y para finalizar el primer 
        ciclo cambiamos el valor de resultado = 0 a resultado = a+b = 1, de esta forma si se puden los dos primer
        digitos de la serie de Fibonacci, la segunda iteracionde bucle inmedetamente se imprimira resultado = 1, que es
        el segunda valor de la serie,y asi sucesivamente, tal que finalmente siempre se esta imprimienda la suma de
        los dos primeros antecesores en la serie de Fibonacci al numero que sera impreso en la siguente iteracion del
        ciclo
        */
    }

    return 0;
}