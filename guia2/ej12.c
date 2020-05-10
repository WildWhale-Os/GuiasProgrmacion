/* 



Timus 1787. Turn for MEGA
timus_ID = TomasBravo
Judge_ID = 295450ZH

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, autosRestantes, autos = 0;
    int carsAtTime[101];
    for (int i = 0; i < 101; i++)
        carsAtTime[i] = 0;

    scanf("%d %d", &k, &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &carsAtTime[i]);

    for (int i = 0; i <= n; i++)
        autos += carsAtTime[i];

    autosRestantes = autos - (n * k);
    printf("%d\n", autosRestantes);
}