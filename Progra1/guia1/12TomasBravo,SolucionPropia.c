/*
Problema:
Resolver el problema "Bicycle Codes en la plataforma Timus. 
Recuerda subir el código y el pantallazo de su código aceptado por la plataforma.
https://acm.timus.ru/problem.aspx?space=1&num=1877
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int clave1; //clave del primer candado
    int clave2; //clave del segundo candado
    scanf("%d", &clave1);// Se leen los numeros entregados por teclado
    scanf("%d", &clave2);// Se leen los numeros entregados por teclado
    
    // Define condiciones de apertura de los candados
    if (clave1 % 2 != 0 && clave2 % 2 == 0) // si la clave de el primer candado es impar y la clave del segundo candado es par
    {
        printf("no\n"); // entonces el ladron nunca podra llevarse la bicicleta
    }
    else // en el caso que la clave1 se par o la clave2 sea impar
    {
        printf("yes\n"); // el ladron eventualmente abrira alguno de las candados.
    }
    

    return 0;
}
