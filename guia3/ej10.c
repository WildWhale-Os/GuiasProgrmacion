/*
Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que pida y lea una cadena de caracteres e 
imprima la misma cadena convirtiendo las letras mayúsculas en minúsculas 
y viceversa, manteniendo los caracteres que no son letras sin alterar.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cad[10000];                                // declaramos un arrego de caracteres donde guardaremos la string que nos entreguen
    printf("Ingrese una cadena de caracteres: \n"); // pedimos la string
    scanf("%[^\n]s", cad);                          // leemos y guardamos la strting que nos entregan
    getchar();                                      // limpiamos el buffer del teclado

    for (int i = 0; i < 32; i++) // por cada caracter en el string entregado
    {
        if (cad[i] >= 'A' && cad[i] <= 'Z')      // verificamos si es una letra mayuscula
            cad[i] += 32;                        // de ser asi le sumamos 32 a su codigo ascii para que se trannsforma en la misma letra pero minuscula
        else if (cad[i] >= 'a' && cad[i] <= 'z') // en caso contrario verificamos si es una letra minuscula
            cad[i] -= 32;                        // de ser asi le restamos 32 a su codigo ascii para convertirla en la misma letra pero mayuscula
    }

    printf("Al invertir las mayusculas y minusculas en la cadena ingreseda da como resultado: \n"); // imrpimimos la cadena pero con las mayusculas y minusculas invertidas.
    printf("%s\n", cad);

    return 0;
}