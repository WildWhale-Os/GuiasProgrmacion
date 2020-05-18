/* 

Autor: Tomas Bravo.
Solucion propia.

Problema 8:
Escribe un programa que pida un numero entero n y a continuacion 
lea n coordenadas en dos dimensiones. A continuacion, el programa 
debera imprimir por pantalla las coordenadas ordenadas de menor a 
mayor. En caso de que exista empate entre el componente en las abscisas, 
se debera comparar el valor en las ordenadas. El programa debera verificar 
que la entrada sea valida, con n positivo.

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sizeArray; // declaramos la variable donde guardaremos la cantidad de vectores que seran introducidos

    do
    {
        printf("Digite la cantidad de vectores a introducir (un numero mayor a 0): ");
        scanf("%d", &sizeArray);

    } while (sizeArray <= 0); // se pide el numero de vectores a el usuario y si no es mayor a 0 se pedira otro numero

    int vectores[sizeArray][2]; // se declara la matriz que contendra nuesros vectores

    for (int i = 0; i < sizeArray; i++) // se le piden las coordenas de los vectores al usuario
    {
        printf("Digite el vector numero %d (x,y): ", i + 1);
        scanf("%d %d", &vectores[i][0], &vectores[i][1]);
    }
    
    //Primero odenamos las vectores segun el valor de sus abscisas.
    for (int i = 0; i < sizeArray; i++)
    {
        int pos = i;
        int xpos = vectores[i][0], ypos = vectores[i][1];

        while (pos > 0 && vectores[pos - 1][0] > xpos)
        {
            vectores[pos][0] = vectores[pos - 1][0];
            vectores[pos][1] = vectores[pos - 1][1];
            pos--;
        }
        vectores[pos][0] = xpos;
        vectores[pos][1] = ypos;
    }

    // Despues buscamos en las que tengas abscisas iguales pero ordenadas distintas y los colocames en el orden correcto
    for (int j = 0; j < sizeArray; j++)
    {
        int pos = j;
        int xpos = vectores[j][0], ypos = vectores[j][1];

        while (pos > 0 && vectores[pos - 1][0] == xpos)
        {
            if (vectores[pos - 1][1] > ypos)
            {
                vectores[pos][0] = vectores[pos - 1][0];
                vectores[pos][1] = vectores[pos - 1][1];
                pos--;
            }
        }
        vectores[pos][0] = xpos;
        vectores[pos][1] = ypos;
    }
    //imprimimos los vectores ordenadas correctamente de menar a mayor segun los criterios entragados
    printf("Los Vectores Ordenados de menor a mayor: \n");
    for (int i = 0; i < sizeArray; i++)
        printf("(%d, %d)\n", vectores[i][0], vectores[i][1]);

    return 0;
}