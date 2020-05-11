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
    

    scanf("%d %d", &k, &n);

    int carsAtTime[n];
    if (k >= 1 && n <= 100)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &carsAtTime[i]);

        for (int i = 0; i < n; i++)
            autos += carsAtTime[i] - k;

        if(autos < 0)
            autos = 1;
        
        printf("%d\n", autos);
    }

    return 0;
}