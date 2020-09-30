/*
Autor: Tomas Bravo
Solucion: Propia
*/
#include <bits/stdc++.h>

using namespace std;

int algoritm(int num)
{
    int it = 1;
    while (num != 1)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            num = 3 * num + 1;
        it++;
    }
    return it;
}

int BiggestIteracion(int num1, int num2)
{
    int mayor = -1, iteraciones;
    for (int i = num1; i <= num2; i++)
    {
        iteraciones = algoritm(i);
        if (iteraciones > mayor)
            mayor = iteraciones;
    }

    return mayor;
}

int main(int argc, char const *argv[])
{
    bool inNum1 = true;
    int num1, num2, contador,pos = 0;
    std::string todo, snum1, snum2;
    while (scanf("%d %d",&num1,&num2) != EOF)
    {
        contador = num2 > num1? BiggestIteracion(num1, num2):BiggestIteracion(num2, num1);
        cout << num1 << " " << num2 << " " << contador << endl;
    }
    return 0;
}
