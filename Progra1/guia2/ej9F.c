#include <stdio.h>

int main(int argc, char const *argv[])
{
    int mxX, mxY, mnX, mnY, nVectors, mDot[2], x, y;
    printf("Cuantos puntos va a entregar: ");
    scanf("%d", &nVectors);

    while (nVectors < 0)
    {
        printf("El numero ingresado en menor que 0, por favor ingresar un numero mayor o igual a 0: ");
        scanf("%d", &nVectors);
    }

    switch (nVectors)
    {
    case 0:
        printf("Como seran ingresados 0 puntos, el programa terminara");
        break;

    default:

        for (int i = 0; i < nVectors; ++i)
        {
            printf("%d) Ingrese un vector de forma (x,y): ", i+1);
            scanf("%d %d", &x, &y);
            if (i == 0)
            {
                mxX = x;
                mxY = y;
                mnX = x;
                mnY = y;
            }
            else
            {
                if (x > mxX)
                    mxX = x;
                else if (x < mnX)
                    mnX = x;
                if (y > mxY)
                    mxY = y;
                else if (y < mnY)
                    mnY = y;
            }
        }

        mDot[0] = (mnX + mxX)/2;
        mDot[1] = (mnY + mxY)/2;

        printf("EL punto medio del plano formado por los puntos (%d,%d), (%d,%d), (%d,%d) y (%d,%d) es: (%d,%d)\n", mxX, mxY, mnX, mxY, mnX, mnY, mxX, mnY, mDot[0], mDot[1]);
        break;
    }
    return 0;
}
