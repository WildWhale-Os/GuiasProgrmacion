/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

Escriba una función long long mcm(long long n1, long long n2) que recibe un par de números enteros
 y devuelve el mı́nimo común múltiplo de ellos.
*/

#include <stdio.h>

long long mcm(long long n1, long long n2) //declaramos nuestra funcion que recibe como argumentos dos numeros enteros
{
	int i;		   // declaramos nuestra variable de iteracion
	long long MCM; // declaramos la variable que contrenda el Minimo comun multiplo entre los dos numeros entregados
	if (n1 >= n2)  // nos fijamos cual es el mayor de los dos nuemeros entregados
		i = n1;	   // y igualmos la variable de iteracion al numero mayor
	else
		i = n2;
	while (i > 0) // mientras nuestra variable de iteracion sea mayor a 0
	{
		if (i % n1 == 0 && i % n2 == 0) // el primero numero que puede ser divido por ambos numero entregados
		{
			MCM = i; // al encontrarlo lo guardamos en la variable MCM que declramos anteriormente
			break;	 // y terminamos de iterar
		}

		i++; // en cualquier caso aumentamos el iterador en 1
	}

	return MCM; // devolvemos el minimo comun multiplo.
}
