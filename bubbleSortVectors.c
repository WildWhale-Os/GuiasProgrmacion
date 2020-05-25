#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    int matriz[num][2];

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &matriz[i][0], &matriz[i][1]);
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (matriz[i][0] < matriz[j][0])
            {
                int aux1 = matriz[i][0];
                matriz[i][0] = matriz[j][0];
                matriz[j][0] = aux1;
                int aux2 = matriz[i][1];
                matriz[i][1] = matriz[j][1];
                matriz[j][1] = aux2;
            }
            else if (matriz[i][0] == matriz[j][0] && matriz[i][1] < matriz[j][1])
            {
                int aux1 = matriz[i][0];
                matriz[i][0] = matriz[j][0];
                matriz[j][0] = aux1;
                int aux2 = matriz[i][1];
                matriz[i][1] = matriz[j][1];
                matriz[j][1] = aux2;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        printf("(%d,%d)\n", matriz[i][0], matriz[i][1]);
    } 

    return 0;
}
