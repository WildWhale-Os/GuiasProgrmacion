/* 
Autor: Tomas Bravo 
Solucion Propia.
timus_ID = TomasBravo
Judge_ID = 295450ZH

Problema 13:
Timus 1068. Sum


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result = 0, cota;

    scanf("%d", &cota);
    if (cota <= 10000 && cota >= -10000)
    {
        if (cota > 0)
            for (int i = 1; i <= cota; i++)
                result += i;

        else
            for (int i = cota; i <= 1; i++)
                result += i;

        printf("%d\n", result);
    }

    return 0;
}