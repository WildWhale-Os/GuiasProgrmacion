/*
Autor: Tomas Bravo
Tipo de Solucion: Propia

Escriba una función long long mcd(long long n1, long long n2) que recibe un par de números enteros y 
devuelve el máximo común divisor de ellos.
*/

#include <stdio.h>

long long mcd(long long n1, long long n2){
	int i;
	long long MCD;
	if (n1 > n2)
		i = n2;
	else 
		i = n1;

	while(i > 0){
		if(n1 % i == 0 && n2 % i == 0)
		{
			MCD = i;
			break;
		}
		i--;
	}

	return MCD;
}