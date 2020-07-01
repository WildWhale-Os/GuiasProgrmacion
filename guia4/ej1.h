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

double Operaciones(char op, double v1, double v2) // declaramos nuestra funcion que resive dos decimales de punto flotante de presicion doble y un caracter
{
	switch (op) // dependiento del caracter
	{
	case '+':			  // si el caracter es el caracter +
		return (v1 + v2); // le sumamos a v2 a v1 y devolvemos el resultado
		break;
	case '-':			  // si es el caracter -
		return (v1 - v2); //le restamos v2 a v1 y devolvemos el resultado
		break;
	case '*':			  // si es el caracter *
		return (v1 * v2); // multiplicamos v1 con v2 y devolvemos el resultado
		break;
	case '/':			  // si es el caracter /
		return (v1 / v2); // dividimos v1 en v2 y devolvemos el resultado
		break;
	}
}