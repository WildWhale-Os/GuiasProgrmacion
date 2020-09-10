/*
pida dos enteros n, m, luego llene una matriz1[n][m] y matriz2[m][n]
y devuelva la relacion entre estas dos matrices:

"Transpuesta" sin la matriz2 en la transpuesta de la matriz1.
"Contenida", si la matriz2 no es la transpuesta de la matriz1 y si todos los elemtos
de la matriz1 estan contenidos en la matriz2.
"Sin relacion", si no cumple con ninguno de los dos criterios anteriores.

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n , relacion = 1;

	do
	{
		scanf("%d %d", &n, &m);
	} while(n < 0 && m < 0);

	int matriz1[n][m], matriz2[m][n],m1[n*m], m2[m*n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &matriz1[i][j]);
			m1[i*n + j] = matriz1[i][j];
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &matriz2[i][j]);
			m2[i*m + j] = matriz2[i][j];
		}
	}

	
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matriz1[i][j] != matriz2[j][i])
			{
				relacion = 0;
			}
		}
	}
	
	
	
	for (int i = 0; i < n*m; ++i)
	{
		int pos = i;
		int actVal = m1[i];
		while(pos > 0 && m1[pos - 1] > actVal)
		{
			m1[pos] = m1[pos - 1];
			pos--;
		}
		m1[pos] = actVal;
	} 

	for (int i = 0; i < n*m; ++i)
	{
		int pos = i;
		int actVal = m2[i];
		while(pos > 0 && m2[pos - 1] > actVal)
		{
			m2[pos] = m2[pos - 1];
			pos--;
		}
		m2[pos] = actVal;
	} 

	for (int i = 0; i < m*n; ++i)
	{
		if(m1[i] == m2[i])
		{
			relacion = 2;
		}
		
	}
	

	switch(relacion)
	{
		case 1:
			printf("Transpuesta\n");
			break;
		case 2:
			printf("Contenida\n");
			break;
		default:
			printf("Sin relacion\n");
	}

	return 0;
}