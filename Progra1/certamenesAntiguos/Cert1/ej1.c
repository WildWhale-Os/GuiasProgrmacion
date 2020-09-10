/*
Pida 4 numeros y devualva cuantos de ellos
son pares, negativos y cuantos no cumplen
con ninguna de las dos condiciones anteriores.
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int negativos = 0, pares = 0, none = 0, num;

	for(int i = 0; i < 4; i++)
	{
		scanf("%d", &num);
		if (num%2 == 0 || num < 0)
		{
			if (num%2==0)
				pares++;
			
			if (num < 0)
				negativos++;
			
		}
		else
			none ++;
	}

	printf("Entregaste %d numeros pares, %d numeros negativos y %d  impar positivo\n",pares,negativos,none);
	return 0;
}
			
			