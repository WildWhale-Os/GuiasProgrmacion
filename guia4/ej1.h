/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

Escriba una función llamada operacion que reciba tres parámetros: op, v1, v2.
op es un caracter, y v1 y v2 son números de coma flotante de precisión doble. La función
deberá devolver un número de precisión doble, que corresponde al resultado de sumar, restar,
multiplicar o dividir v1 y v2, dependiendo de si el valor de op es +, -, * o /

*/
#include <stdio.h>
#include <stdlib.h>

double Operaciones (char op, double v1, double v2)
{
	switch(op)
	{
		case '+':
			return (v1 + v2);
			break;
		case '-':
			return (v1 - v2);
			break;
		case '*':
			return (v1 * v2);
			break;
		case '/':
			return (v1 / v2);
			break;
		
	}
}