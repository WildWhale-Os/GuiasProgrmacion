/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

Escriba una función long long mcm(long long n1, long long n2) que recibe un par de números enteros
 y devuelve el mı́nimo común múltiplo de ellos.
*/

#include <stdio.h>


long long mcm(long long n1, long long n2)
{
	int i;
	long long MCM;
	if(n1 >= n2)
		i = n1;
	else
		i = n2;
	while(i > 0)
	{
		if(i % n1 == 0 && i % n2 == 0)
		{
			MCM = i;
			break;
		}

		 i++;
	}

	return MCM;
}

