
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

int MenuInicio();								   // declaramos la funcion que nos mostrara el menu de inicio
int MenuMcm();									   //declaracion de la funcion que nos mostrara el menu para buscar minimo comun multiplo
int MenuMcd();									   // declaracion de la funcion que nos mostrara el menu para buscar maximo comun divisor
int MenuOperaciones();							   // declaracion de la funcion que nos mostrara el menu para realizar la operaciones basica entre dos numeros
long long mcm(long long n1, long long n2);		   // declaracion de la funcion que busca el minimo comun multiplo
long long mcd(long long n1, long long n2);		   // declaracion de la funcion que busca el maximo comun divisor
double Operaciones(char op, double v1, double v2); // declaracionde la funcion que calcula una de las cuatro operaciones basicas entre dos numeros entregados

int main(int argc, char const *argv[])
{
	char op;			   // en este char guardaremos la operacion que se quiera realizar enter dos numeros en caso de que se eliga realizar operaciones
	int opcion, aux;	   // variables que usaremos para seguir la progresion del programa
	opcion = MenuInicio(); // inicializamos opcion con al opcion elegida del menu de inicio
	long long n1, n2;	   // definimos nuestras varaaiables donde guardamos los numeros que nos sean entregados
	while (1)			   // un bucle infinito
	{
		switch (opcion) // dependiendo de la opcion elegida en el menu de inicio
		{
		case 1:				 // si es 1
			aux = MenuMcm(); // auxiliar sera igual a la opcion elegida del menu de Busqueda de minimo comun multiplo
			switch (aux)	 // dependiendo del valor que tenga aux
			{
			case 1: // si es uno

				printf("Ingrese dos numeros: ");															 // le pedimo al usuario que entregue dos numeros
				scanf("%lld%lld", &n1, &n2);																 // los leemos y guardamos
				printf("El Minimo Comun Multiplo entre %lld y %lld es igual a %lld\n", n1, n2, mcm(n1, n2)); // y le devolvemos el valor del minimo comun multiplo entre ambos numeros entregados
				return 0;																					 // terminamos el programa
				break;

			default:				   // cualquier otra opcion elegida
				opcion = MenuInicio(); // se volvera a desplegar el muni de inicio y se volvera a leer que opcion es elegida por el usuario
				break;				   // salimos del switch
			}
			break;
		case 2:				 // en caso de que la opcion sea igual a 2
			aux = MenuMcd(); // desplegamos el menu de maximo comun divisor y guardamos la opcion elegida en la variable aux
			switch (aux)	 // depeindiendo del valor de aux
			{
			case 1:																							// si es 1
				printf("Ingrese dos numeros: ");															// le pedimos dos numeros
				scanf("%lld%lld", &n1, &n2);																// los leemos y guardamos
				printf("El Maximo Comun Divisor entre %lld y %lld es igual a %lld\n", n1, n2, mcd(n1, n2)); // le devolvemos el valor del maximo comun divisor de los dos numeros entregados
				return 0;																					// terminamos el programa
				break;

			default:				   // si aux tiene cualquier valor aparte de 1
				opcion = MenuInicio(); // volvemos al menu de incio y leemos de nuevo la opcion del usuario
				break;
			}
			break;
		case 3:						 // si la opcion es la numero 3
			aux = MenuOperaciones(); // desplegamos el menu de operaciones y guardamos la opcion elegida poer el usuario en la variable aux
			switch (aux)			 // igualmente dependiendo del valor de aux
			{
			case 1:																							  // si valor 1
				printf("Ingrese en formato n1 op(+,-,*,/) n2, sin espacios entre cada componente: ");		  // que entregue dos numeros y un caracter que representa la operacion que se quiere realizar entre ambos numeros
				scanf("%lld %c %lld", &n1, &op, &n2);														  // leemos los dos numeros y el caracter
				printf("El resultado de la operacion entregada es igual a %.2lf\n", Operaciones(op, n1, n2)); // y le imrpimimos en pantalla el resultado de la operacion
				return 0;																					  // terminamos el programa
				break;

			default:				   // en caso de que aux sea distinto de 1
				opcion = MenuInicio(); // volvemos al menu de inicio
				break;
			}
			break;
		case 4:		  // en caso de que la opcion elegida del menu de incio sea la ultima
			return 0; // simplemente terminamos el programa
			break;
		}
	}

	return 0;
}

int MenuInicio() // definimos la funcion de menu de incio
{
	char cadena[30];																																																										 // declaramos un arreglo de caracteres donde se guararala opcion elegida por el usuario
	system("clear");																																																										 // limpiamos la pantalla
	printf("Este programa es capaz de calcular el mcm, mcd, suma, resta, division y multiplicacion de dos numeros enteros,\ndependiendo de la operacion que quiera realizar escriba:\n- operacion(+,-,/,*)\n- mcm\n- mcd\n- salir\nCual es su eleccion?: "); // le desplegamos las intrucciones al usurio del uso de programa y de sus opciones a elegir
	scanf("%s", cadena);																																																									 // leemos la opcion que el usuario introdusca
	if (strcmp("mcd", cadena) && strcmp("mcm", cadena) && strcmp("operacion", cadena) && strcmp("salir", cadena))																																			 // si la opcion entregada no se encuentra entre la opciones volvemos a desplegar el menu de incio
		MenuInicio(cadena);

	if (!strcmp("mcm", cadena)) // si la cadena es igual a mcm retornamos 1
		return 1;
	if (!strcmp("mcd", cadena)) // si la cadena es igual a mcd retornamos 2
		return 2;
	if (!strcmp("operacion", cadena)) // si la dena es igual a operacion devolvemos 3
		return 3;
	if (!strcmp("salir", cadena)) // si la cadena es igual a salir retornamos 4
		return 4;
}

int MenuMcm() // esta funcion muetra el submenu del calculo del munimo comun multiplo
{
	int opcion; // declaramos la variable que contendra la opcion elegida por el usuario
	printf("-------------------------------------------------------------------------\n");
	printf("\t\tMinimo Comun Multiplo\n");
	printf("-------------------------------------------------------------------------\n");
	printf("1: Ingrese dos numeros\n"); // le entregamos las opciones al usuario
	printf("2: Volver al menu de inicio\n");
	printf("Ingresar eleccion(numero): "); // le pedimos que ingrese el indice de la opcion elegida
	scanf("%d", &opcion);				   // leemos la eleccion
	return opcion;						   // y retornamos esta eleccion
}

int MenuMcd() // esta funcion despliegua el submenu del calculo de maximo comun divisor
{
	int opcion; // opcion sera la variable donde guardaremos las eleccion del usuario
	printf("-------------------------------------------------------------------------\n");
	printf("\t\tMaximo Comun Divisor\n");
	printf("-------------------------------------------------------------------------\n");
	printf("1: Ingrese dos numeros\n"); // le entregamos las opciones que puede elegir al usuario
	printf("2: Volver al menu de inicio\n");
	printf("Ingresar eleccion(numero): "); // le pedimos que ingrese el numeros de opcion que eligio
	scanf("%d", &opcion);				   // leemos la opcion
	return opcion;						   // y la devolvemos
}
int MenuOperaciones() // funcio despliega el submenu de operaciones
{
	int opcion; // variable donde guardaremos la opcion elegida por el usuario
	printf("-------------------------------------------------------------------------\n");
	printf("\t\tOperaciones\n");
	printf("-------------------------------------------------------------------------\n");
	printf("1: Ingresar operacion\n"); // le entregamos las opciones disponibles al usuario
	printf("2: Volver al menu de inicio\n");
	printf("Ingresar eleccion(numero): "); // le pedimos que ingrese el indice de su eleccion
	scanf("%d", &opcion);				   // leemos el numeros y lo guardamos
	return opcion;						   // finalmente devolvemos la eleccion del usuario
}

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