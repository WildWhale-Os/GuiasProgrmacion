/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba una función long long mcd(long long n1, long long n2) que recibe un par de números enteros y 
devuelve el máximo común divisor de ellos.
*/

#include <stdio.h>

long long mcd(long long n1, long long n2) // definimos la funcion que buscara el maximo comun divisor entre dos numeros
{
	int i;		   // definimos nuestro iterador
	long long MCD; // y la variable que finalmente contedra nuestro numero buscado
	if (n1 > n2)   // dependiendo de cual de los dos numeros entregado sea el menor
		i = n2;
	else // sera nuestro punto de partido, por lo tanto igualamos el iterador a al numero menor entre los dos numero entregados
		i = n1;

	while (i > 0) // mientras el iterador sea mayor que 0
	{
		if (n1 % i == 0 && n2 % i == 0) // buscaremos un numero que sea capaz de dividir a ambos numeros entregados partiendo por el valor del menor de los dos
		{
			MCD = i; // si se ecnuentra un numeros que divida ambos numeros entregados este sera el numero buscado y lo guardamos en la variable correspondiente
			break;	 // y rompemos el ciclo
		}
		i--; // en cualquier caso por cada iteracion vamos a ir disminuyendo el valor del iterador en 1 cada vez hastq ue sea igual a 0
	}

	return MCD; // finalmnte devolvemos el valor que corresponde al maximo comun divisor de ambos numeros
}