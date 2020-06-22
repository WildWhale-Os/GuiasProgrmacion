/*

Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe un programa que pida un número entero n, a continuación, pida ingresar n números 
de coma flotante (usar precisión doble) y luego imprima: el menor (en notación científica), 
el mayor (siempre incluyendo el signo y ocupando, al menos, 10 caracteres), la media (que ocupe, 
al menos, 10 caracteres y tenga dos decimales de precisión), la mediana (con 4 decimales de precisión), 
la desviación media(con 2 decimales de precisión), la desviación estándar (en el formato más corto, con 3 
decimales de precisión) y la varianza (en el formato más corto) del conjunto de números.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;                                      // delcaramos la variable donde sera guardada el numero pedido
    printf("Cuantos numeros va a irngresar: "); // pedimos un numero entero al usuario
    scanf("%d", &n);                            //leemos el numero entregado por el usuario
    while (n < 0)                               // si el numero no es n > 0
    {
        printf("No podemos procesar una cantidad negativa de numeros, porfavor ingresar un numero mayor a 0: "); // se le pedira otro numero el usuario que sea mayor o igual a 0
        scanf("%d", &n);                                                                                         // volvemosremos a leer y a guardar el numero que es entregado
    }
    float numeros[n];                                            // declaramos un arreglo de numero de punto flotante de tamayo n
    float media = 0, mediana, varianza = 0, desviacionMedia = 0; // declaramos las variables donde se guardaran los varloras que cada una describe
    for (int i = 0; i < n; ++i)                                  // se le pediara al usuario que ingrese n numeros
    {
        //printf("%d) Ingrese un numero: ", i + 1);
        scanf("%f", &numeros[i]); // leeremos cada uno de los numeros ingresados y los guardaremos en  el arreglo defino anteriormente
        media += numeros[i];      // y sumaremos el valor a la vriable que almacena el valor de la media de los datos que seran entregados
    }

    for (int i = 0; i < n; ++i) //luego por cada uno de los elementos del arreglo
    {
        int pos = i;                                                                                 // guardamos la posicion en la que estamos
        float error = 0.00001, actNum = numeros[i];                                                  // definimos el error por el cual puede fallar la comparacionde numero flotantes, y guadarmos el valor del numero en la posicion i del arreglo
        while (pos >= 0 && (numeros[pos - 1] - actNum) >= 0 && (numeros[pos - 1] - actNum) >= error) // mientras que la posicion en la que estamos enm el arreglo no sea 0 y el numero en la poscion anterior a nuestra posicion actual haremos
        {
            numeros[pos] = numeros[pos - 1]; // copiaremos en numero en la posicion anterior a la actual en nuestra posicion actual
            pos--;                           // y bajamos una posicion
        }
        numeros[pos] = actNum;                         // cuando ya no encontremos numero mayores que el numero actual en posicion anteriores a la que el esta ,copiamos el numero en la posicion actual
        varianza += pow(abs(actNum - (media / n)), 2); // vamos sumandos cantidades a la variable que representa a la varianza segun su formula
        desviacionMedia += abs(actNum - (media / n));  // y sumamos valores a la variable que representa a la desviacion media segun su formula
    }

    if (n % 2 == 0)                                          // luego comprobamos que el conjunto de datos es par o no
        mediana = (numeros[n / 2] + numeros[n / 2 - 1]) / 2; // si es par la mediana se encontrara el la media de los dos datos centrales
    else                                                     // si el conjutno de datos es impar
        mediana = numeros[(n - 1) / 2];                      // la mediana sera el dato que se entcuentra en la mitad del arreglo

    printf("Resultados del procesamientos: \n");
    printf("El menor numero entregado escrito en notacion centifica es %.3e\n", numeros[0]);                // luego imrpimimos el numero menor del conjunto en su representacion exponencial
    printf("El mayor numero del conjunto de datos entregado es %*f\n", 10, numeros[n - 1]);                 // el mayor del conjunto usando al menos 10 caracteres
    printf("La media del conjunto de datos entregado es igual a %*.2f\n", 10, media / n);                   // de momento la variable que contiene el valor de la media solo a guardado las sumas de todas los elemtos del conjunto entregado ahora la dividimos en el total de datos y la imprimimos.
    printf("La mediana del conjunto de datos entregado es igual a %.4f\n", mediana);                        //imprimimos el valor de la mediana
    printf("La varianza del conjunto de datos entregado es igual a %.0f\n", varianza / n);                  // dividimos el valor de la varianza en el total de datos ya que es lo que nos faltaba de la formula de la varianza y la imprimimos en la pantalla
    printf("La desviacion media del conjunto de datos entregado es igual a %.2f\n", desviacionMedia / n);   // hasta el momento la disviacion media solo posee las sumas de solos los valores absolutos de las restas de los numero entregados restados con la media solo nos falta dividirla por el total de datos e imprimirla
    printf("La desviacion estandar del conjunto de datos entregado es igual a %.3g\n", sqrt(varianza / n)); // deviacion estandar el la raiz cuadrada de la varianza , por lo que sacamos las desviacion estandar de la varianza y imprimimos el valor en pantalla.

    return 0;
}