/*
Autor: Tomas Bravo
Solucion : Propia
*/

#include <bits/stdc++.h>

using namespace std;

void PrintWaves(int ampl, int frec)
{

    for (int i = 0; i < frec; i++)
    {

        int avanze = 1;
        int altura = 1;
        while (altura != 0)
        {
            for (int j = 0; j < altura; j++)
            {
                cout << altura;
            }
            cout << endl;
            if (altura == ampl)
                avanze *= -1;
            altura += avanze;
        }
        if(i < frec -1)
            cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int entradas;
    cin >> entradas;
    int datos[entradas][2];
    for (int i = 0; i < entradas; ++i)
        cin >> datos[i][0] >> datos[i][1];

    for (int i = 0; i < entradas; i++)
    {
        PrintWaves(datos[i][0], datos[i][1]);
        if (i != entradas - 1)
            cout << endl;
        
    }
    return 0;
}
