/* 

Autor: Tomas Bravo

Escribe un programa que pida un número entero n y a continuación imprima 
los n primeros niveles del triángulo de pascal. El programa deberá verificar 
que la entrada sea válida (n positivo).

*/
#include <stdio.h>

int main()
{
    int nNiveles; //declaracion de la variable donde se guardaran la cantidad de niveles a imprirmir

    do
    { // se le pide al usuario que digite un numero que sea mayor que 0 de no serlo se le pedira otro numero
        printf("Cuantos niveles de la triangulo de pascal quiere imprimir: ");
        scanf("%d", &nNiveles);
    } while (nNiveles < 0);

    int base[nNiveles]; // se declara un arreglo con igual cantidad de datos a numero de niveles a imprimir

    for (int i = 0; i < nNiveles; i++) // se llena el array con puros 0
    {
        base[i] = 0;
    }

    base[0] = 1; // se cambia el primer valor del array por un 1

    for (int i = 0; i < nNiveles; i++) // se declara un bucle que se realizara nNiveles cantidad de veces
    {                                  //para imprimrir nNiveles del triangulo de pascal

        for (int k = nNiveles; k > 0; k--) // se recorre el array de atras hacia adelante
        {
            if (base[k - 1] != 0)           // si el valor anterior a la posicion actual en el array es != de 0
                printf("%i ", base[k - 1]); // se imprime el numero anterior al de la posicion actual.
            base[k] += base[k - 1];         // se le suma el valor de la posicion anterior del arreglo al valor de la posicion actual.
        }

        printf("\n");
    }

    return 0;
}