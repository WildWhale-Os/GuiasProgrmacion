/*
Problema:
Resolver el problema "About Grisha N. en la plataforma Timus. 
Recuerda subir el código y el pantallazo de su código aceptado por la plataforma.
https://acm.timus.ru/problem.aspx?space=1&num=2012
*/
#include <stdio.h>

int main(void)
{
    int preguntas; // preguntas realizadas en la primera hora de prueba
    int demora;
    scanf("%i", &preguntas); // Lectura de datos entrgados por teclado

    if (1 <= preguntas && preguntas <= 11) // si valor de preguntas realizadas dentro de la primera hora de prueba vive en [1,11]
    {
        demora = (((12 - preguntas) * 45) / 60) + 1; // Calcular las horas que se demorara en hacer la prueba completa

        if (demora >= 5) // si se demora 5 o mas horas
        {
            printf("NO\n"); // imprimir ""NO"
        }
        else // si se demora menos de 5 horas
        {
            printf("YES\n"); // imprimir "SI"
        }
    }

    return 0;
}