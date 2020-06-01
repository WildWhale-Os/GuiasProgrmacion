#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, shortest[2];                                // declaramos las variable que contendra cuantos ruts y cuantas edades seran ingresadas y el arreglo que contendra el RUT y la edad de la persona con el menor rut entregado
    printf("Cuantos RUT y edades seran entregados: "); // se pide la cantidad de par de datos que seran ingresados
    scanf("%d", &n);                                   // lo guardamos en n
    while (n <= 0)                                     // verificamos que sea un numero positivo
    {
        printf("No se pueden procesar 0 RUTs y 0 edades menos aun, cantidades negativas de estas mismas.\nIngrese un numero mayor a 0, porfavor: "); // de no serlo se le pedira otro numero al usuario
        scanf("%d", &n);                                                                                                                             // y se guardara el numero ingresado en n
    }
    printf("Entregue en %d pares de numeros.\nConformados por el RUT (sin digito verificador) y la edad correspondiente de la persona: \n",n); // ahora pedimos los rut y las edad
    for (int i = 0; i < n; ++i)                                                                                         // de n personas
    {
        int rut, edad;               // declaramos dos variables temporalos
        scanf("%d %d", &rut, &edad); // leemos el Rut de la persona y la edad de la persona
        if (i == 0)                  // si es el primer ingreso inicilizamos el rut mas corto con los datos recien entregados
        {
            shortest[0] = rut;
            shortest[1] = edad;
        }
        else if (rut < shortest[0]) // para el resto de lecturas comparamos el RUT recien ingresado con el rut de la persona con el menor RUT
        {
            shortest[0] = rut;  // si el RUT recien ingresado es menor al RUT mas chico, cambiamos el valor del Rut mas chico
            shortest[1] = edad; // y la edad la cambiamos a la edad correpondiente a la persona con el RUT mas chico
        }
        else if (rut == shortest[0]) // si los Ruts son iguales
            if (edad > shortest[1])  // verificamos cual el que tiene mas edad
                shortest[1] = edad;  // y nos quedamos con la mayor edad
    }

    printf("Edad de la persona con el menor RUT: %d\n", shortest[1]); //finalmente imprimimos la edad de la personas con el rut mas chico

    return 0;
}