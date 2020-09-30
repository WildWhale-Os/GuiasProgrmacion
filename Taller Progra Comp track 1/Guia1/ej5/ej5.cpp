/*
Autor: Tomas Bravo
Solucion : Propia
*/

#include <bits/stdc++.h>

using namespace std;

long Miembro(int &valor, int &exponente)
{
    long result = pow(valor, exponente);
    return result;
}

long Polinomio(vector<int> indices, int &valor)
{
    long resultado = 0;
    for (int i = indices.size() - 1, j = 0; i >= 0; --i, j++)
    {
        resultado += Miembro(valor, j) * indices[i];

    }

    return resultado;
}

int main()
{
    vector<int> poly;
    vector<int> numeros;
    int i = 0, j = 0, in1;
    char c;
    bool on = true;
    while (on)
    {
        do
        {
            scanf("%d%c", &in1, &c);
            poly.push_back(in1);
            i++;
        } while (c != '\n');
        i = 0;
        do
        {
            if (scanf("%d%c", &in1, &c) == EOF)
            {
                on = false;
                break;
            }
            numeros.push_back(in1);

            j++;
        } while (c != '\n');

        if (on)
        {
            for (j = 0; j < numeros.size(); j++)
            {
                if (j < numeros.size() - 1)
                    cout << Polinomio(poly, numeros[j]) << " ";
                else
                    cout << Polinomio(poly, numeros[j]) << endl;
            }
            while (!numeros.empty())
            {
                numeros.pop_back();
            }
            while (!poly.empty())
            {
                poly.pop_back();
            }
        }
        j = 0;
    }

    return 0;
}
