/*

Autor: Tomas Bravo
Solucione propia.

timus_ID = TomasBravo
Judge_ID = 295450ZH

Porblema 14:
Timus 1991. The battle near the swamp


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int droidsGroups, droidsPerGroup, boomBooms, boomBoomLeft = 0, droidsLeft = 0; //definimos variables
    scanf("%d %d", &droidsGroups, &droidsPerGroup);                                // pedimos el numero de grupos de droides y la cantidad de droides por grupo
    if (droidsGroups >= 1 && droidsPerGroup <= 10000)                              // si o si debe haber 1 grupo o mas y cada grupo debe tener 10.000 o menos droides
    {
        for (int i = 0; i < droidsGroups; i++) // por cada grupo de droide que haya se pedira un camion con boombooms
        {
            scanf("%d", &boomBooms);                   // se lee cuantas boombooms tendra cada camion
            if (boomBooms >= 0 && boomBooms <= 100000) // los camiones deben tener como minimo 0 boombooms y como maximo 100.000 boombo0ms
            {
                if (droidsPerGroup - boomBooms > 0) // si por cada grupo de droides hay mas droides que boombooms se suma los droides restantes a la respectiva variable
                    droidsLeft += droidsPerGroup - boomBooms;
                else // si hay mas boombooms que droides en un grupo se le suma la cantidad de boombooms restante a la respectiva variable.
                    boomBoomLeft += boomBooms - droidsPerGroup;
            }
        }

        printf("%d %d\n", boomBoomLeft, droidsLeft); // se imprime as boombooms restantes y el numero total de droides que sobrevivieron.
    }

    return 0;
}