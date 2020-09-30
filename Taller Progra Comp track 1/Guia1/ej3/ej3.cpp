/*
autor: Tomas Bravo
Solucion: propia
*/
#include <bits/stdc++.h>

using namespace std;

bool Just1CommonFactor(int num1, int num2)
{
    if (__gcd(num1,num2) == 1)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    int tam;
    double contador = 0;

    bool control = true;
    scanf("%d", &tam);
    while (tam != 0)
    {
        double combinaciones = (tam * (tam - 1)) / 2;
        int arreglo[tam];
        for (int i = 0; i < tam; i++)
            cin >> arreglo[i];
        for (int i = 0; i < tam - 1; i++)
        {
            for (int j = i + 1; j < tam; j++)
            {
                bool condition = arreglo[i] > arreglo[j] ? Just1CommonFactor(arreglo[j], arreglo[i]) : Just1CommonFactor(arreglo[i], arreglo[j]);
                if (condition)
                    contador++;
            }
        }
        if (contador < 1)
            cout << "No estimate for this data set." << endl;
        else
            cout << fixed << setprecision(6) << sqrt((6 * combinaciones) / contador) << endl;
        scanf("%d", &tam);
        contador = 0;
    }

    return 0;
}