/*

Autor: Tomas Bravo
Solucion Propia.

timus_ID = TomasBravo
Judge_ID = 295450ZH

Problema 15:
Timus 1880 Psych Up's Eigenvalues

Ques e busca?
de tres grupos destintos de numeros de n,m,r longitud, cuantos valores en comun poseen.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int eigenValues = 0, size1, size2, size3;

    // pedimos la cantidad de datos que se ingresaran en nuestro primer grupo de valores
    scanf("%d", &size1);
    int valores1[size1];
    //pedimos los datos y los guardamos
    for (int i = 0; i < size1; i++)
        scanf("%d", &valores1[i]);

    // pedimos la cantidad de datos que se ingresaran en nuestro segundo grupo de valores
    scanf("%d", &size2);
    int valores2[size2];
    //pedimos los datos y los guardamos
    for (int i = 0; i < size2; i++)
        scanf("%d", &valores2[i]);

    // pedimos la cantidad de datos que se ingresaran en nuestro tercer grupo de valores
    scanf("%d", &size3);
    int valores3[size3];
    //pedimos los datos y los guardamos
    for (int i = 0; i < size3; i++)
        scanf("%d", &valores3[i]);

    for (int i = 0; i < size1; i++)         // por cada elemento del primer grupo de numeros
        for (int j = 0; j < size2; j++)     // buscamos en el segundo grupo de numeros
            if (valores1[i] == valores2[j]) //si exite uno igual
            {
                for (int r = 0; r < size3; r++) // si es asi buscamos en el tercer grupo de numeros si existe uno igual a las otro dos numero
                    if (valores3[r] == valores2[j])
                    {
                        eigenValues++; // de ser asi agregamos 1 a la lista de numeros que se encuentras en los tres conjuntos de numeros
                        break;
                    }
                break;
            }

    printf("%d\n", eigenValues); // imprimimos la cantidad de numeros que estan presentes en las tres conjuntos de numeros.

    return 0;
}
