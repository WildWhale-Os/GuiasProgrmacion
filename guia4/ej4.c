
/*
Autor: Tomas Bravo
Tipo de Solucion: Propia.

Escriba un programa que incluya las funciones anteriormente solicitadas:
operacion, mcm y mcd y pregunte al usuario por la operación que desea realizar. 
El programa deberá imprimir un mensaje dando instrucciones sobre el uso del mismo. 
Posteriormente, el programa aceptará como entrada, únicamente, una de las siguientes cadenas 
de caracteres: operacion, mcm, mcd y salir, en caso de introducir cualquier otra cadena, se 
limpiará la pantalla y se volverá a desplegar el mensaje con las instrucciones. En caso de que 
el usuario ingrese cualquiera de las tres primeras instrucciones, se entrará a un sub-menú 
con instrucciones propias de la operación. Para el caso de operacion, se desplegará un menú 
con la opciones 1: ingresar operacion y 2: Volver al menú principal. En caso de seleccionar la
opción 1, el programa deberá leer los dos números y el caracter correspondiente e imprimir la respuesta. 
Se debe validar la entrada y comprobar que se introdujeron dos números y un caracter. 
En caso de seleccionar la opción 2, el programa deberá limpiar la pantalla y volver a desplegar el 
mensaje de instrucciones y esperar una cadena de caracteres. En caso de que el usuario ingrese, en el 
menú principal, mcm o mcd, el programa desplegará un menú análogo al de operacion, pero asociado a las 
operaciones correspondientes. En ambos casos, el menú estará compuesto por las opciones 1: ingresar números 
y 2: Volver al menú principal. La opción
2 es análoga a la del menú de operacion y la opción 1, ingresa a una pantalla en la que se piden y 
se validan dos números enteros y se despliega el resultado (ya sea el mcm o el mcd). En el caso de 
los tres sub-menús, si se ingresa una opción inválida, se deberá limpiar la pantalla y seguir mostrando el 
sub-menú correspondiente. Finalmente, si en el menú principal, se ingresa la cadena salir, el programa 
termina su ejecución.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MenuInicio(char *cadena);
int MenuMcm();
int MenuMcd();
int MenuOperaciones();
long long mcm(long long n1, long long n2);
long long mcd(long long n1, long long n2);
double Operaciones(char op, double v1, double v2);

int main(int argc, char const *argv[])
{
	char cadena[30];
	char op;
	int opcion, aux;
	opcion = MenuInicio(cadena);
	long long n1, n2;
	while (1)
	{
		switch (opcion)
		{
		case 1:
			aux = MenuMcm();
			switch (aux)
			{
			case 1:

				printf("Ingrese dos numeros: ");
				scanf("%lld%lld", &n1, &n2);
				printf("El Minimo Comun Multiplo entre %lld y %lld es igual a %lld\n", n1, n2, mcm(n1, n2));
				return 0;
				break;

			default:
				opcion = MenuInicio(cadena);
				break;
			}
			break;
		case 2:
			aux = MenuMcd();
			switch (aux)
			{
			case 1:
				printf("Ingrese dos numeros: ");
				scanf("%lld%lld", &n1, &n2);
				printf("El Maximo Comun Divisor entre %lld y %lld es igual a %lld\n", n1, n2, mcd(n1, n2));
				return 0;
				break;

			default:
				opcion = MenuInicio(cadena);
				break;
			}
			break;
		case 3:
			aux = MenuOperaciones();
			switch (aux)
			{
			case 1:
				printf("Ingrese en formato n1 op(+,-,*,/) n2, sin espacios entre cada componente: ");
				scanf("%lld %c %lld", &n1, &op, &n2);
				printf("El resultado de la operacion entregada es igual a %.2lf\n", Operaciones(op, n1, n2));
				return 0;
				break;

			default:
				opcion = MenuInicio(cadena);
				break;
			}
			break;
		case 4:
			return 0;
			break;
		}
	}

	return 0;
}

int MenuInicio(char *cadena)
{
	system("clear");
	printf("Este programa es capaz de calcular el mcm, mcd, suma, resta, division y multiplicacion de dos numeros enteros,\ndependiendo de la operacion que quiera realizar escriba:\n- operacion(+,-,/,*)\n- mcm\n- mcd\n- salir\nCual es su eleccion?: ");
	scanf("%s", cadena);
	if (strcmp("mcd", cadena) && strcmp("mcm", cadena) && strcmp("operacion", cadena) && strcmp("salir", cadena))
	{
		system("clear");
		MenuInicio(cadena);
	}
	if (!strcmp("mcm", cadena))
		return 1;
	if (!strcmp("mcd", cadena))
		return 2;
	if (!strcmp("operacion", cadena))
		return 3;
	if (!strcmp("salir", cadena))
		return 4;
}

int MenuMcm()
{
	int opcion;
	printf("-------------------------------------------------------------------------\n");
	printf("\t\tMinimo Comun Multiplo\n");
	printf("-------------------------------------------------------------------------\n");
	printf("1: Ingrese dos numeros\n");
	printf("2: Volver al menu de inicio\n");
	printf("Ingresar eleccion: ");
	scanf("%d", &opcion);
	return opcion;
}

int MenuMcd()
{
	int opcion;
	printf("-------------------------------------------------------------------------\n");
	printf("\t\tMaximo Comun Divisor\n");
	printf("-------------------------------------------------------------------------\n");
	printf("1: Ingrese dos numeros\n");
	printf("2: Volver al menu de inicio\n");
	printf("Ingresar eleccion: ");
	scanf("%d", &opcion);
	return opcion;
}
int MenuOperaciones()
{
	int opcion;
	printf("-------------------------------------------------------------------------\n");
	printf("\t\tOperaciones\n");
	printf("-------------------------------------------------------------------------\n");
	printf("1: Ingresar operacion\n");
	printf("2: Volver al menu de inicio\n");
	printf("Ingresar eleccion: ");
	scanf("%d", &opcion);
	return opcion;
}

double Operaciones(char op, double v1, double v2)
{
	switch (op)
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

long long mcm(long long n1, long long n2)
{
	int i;
	long long MCM;
	if (n1 >= n2)
		i = n1;
	else
		i = n2;
	while (i > 0)
	{
		if (i % n1 == 0 && i % n2 == 0)
		{
			MCM = i;
			break;
		}

		i++;
	}

	return MCM;
}

long long mcd(long long n1, long long n2)
{
	int i;
	long long MCD;
	if (n1 > n2)
		i = n2;
	else
		i = n1;

	while (i > 0)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			MCD = i;
			break;
		}
		i--;
	}

	return MCD;
}