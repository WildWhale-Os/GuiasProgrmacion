#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;                                  // declaramos variable que sera el largo de nuestros arrglos
    printf("Digite un numero mayor a 0: "); // se le pide el largo de los arreglos al usuario
    scanf("%d", &n);                        // se lee el numero y se guarda en nuestra variable n
    while (n <= 0)                          // verificamos que sea un numero positivo
    {
        printf("El numero entregado no es positivo, intente de nuevo: "); // de otra forma se pedira otro numero
        scanf("%d", &n);                                                    // y se volvera a leer y almacenar el numero entregado en n
    }
    printf("Digite dos conjuntos de numero, cada uno en una linea distinta, y cada numero separado con un espacion:\n");
    int arr1[n], arr2[n]; // declaramos nuetros dos arreglo de largo n
    // pedimos los valores del primer arreglo
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr1[i]);
        while (arr1[i] <= 0) // validamos que todos los numero entregados sean mayores que 0
        {
            printf("El numero entregado no es positivo, intente de nuevo: ");
            scanf("%d", &arr1[i]);
        }
    }

    //pedimos los valores del segundo arreglo
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr2[i]);
        while (arr2[i] <= 0) // validamos que todos los numero entregados sean mayores que 0
        {
            printf("El numero entregado no es positivo,intente de nuevo: ");
            scanf("%d", &arr2[i]);
        }
    }

    // ordenar arr1
    for (int i = 0; i < n; ++i)
    {
        int pos = i, actual = arr1[i];
        while (pos > 0 && arr1[pos - 1] > actual)
        {
            arr1[pos] = arr1[pos - 1];
            pos--;
        }
        arr1[pos] = actual;
    }

    //ordenar arreglo 2
    for (int i = 0; i < n; ++i)
    {
        int pos = i, actual = arr2[i];
        while (pos > 0 && arr2[pos - 1] > actual)
        {
            arr2[pos] = arr2[pos - 1];
            pos--;
        }
        arr2[pos] = actual;
    }
    // imprimimos en pantalla el arreglo de distancias resultantes
    for (int i = 0; i < n; ++i)
    {
        arr1[i] = abs(arr1[i] - arr2[i]);
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}