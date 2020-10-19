/*
Autor: Tomas Bravo
Solucion: Propia
*/
#include <bits/stdc++.h>

using namespace std;

bool tresVerticales(char &elem, char tablero[][3])
{
    int cont = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (tablero[j][i] == elem)
                cont++;
        }
        if (cont == 3)
            return true;
        cont = 0;
    }
    return false;
}

bool tresHorizontal(char &elem, char tablero[][3])
{
    int cont = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (tablero[i][j] == elem)
                cont++;
        }
        if (cont == 3)
            return true;
        cont = 0;
    }
    return false;
}

bool tresDiagonal(char &elem, char tablero[][3])
{
    int cont = 0;
    for (int i = 0, j = 0; i < 3, j < 3; i++, j++)
        if (tablero[i][j] == elem)
            cont++;
    if (cont == 3)
        return true;
    cont = 0;
    for (int i = 0, j = 2; i < 3, j > 0; i++, j--)
        if (tablero[i][j] == elem)
            cont++;
    if (cont == 3)
        return true;
    return false;
}

bool isCharGinner(char elem, char tablero[][3])
{
    if (tresHorizontal(elem, tablero) || tresVerticales(elem, tablero) || tresDiagonal(elem,tablero))
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int exes = 0, os = 0, posx = 0, posy = 0;
        char tablero[3][3];
        for (int j = 0; j < 3; j++)
        {
            string entrada;
            cin >> entrada;
            for (int k = 0; k < entrada.length(); k++)
            {
                if (entrada.at(k) == 'X')
                    exes++;
                else if (entrada.at(k) == 'O')
                    os++;
                if (entrada.at(k) == 'O' || entrada.at(k) == 'X' || entrada.at(k) == '.')
                {
                    tablero[posx][posy] = entrada.at(k);
                    posy++;
                    if (posy > 2)
                    {
                        posy = 0;
                        posx++;
                    }
                }
            }
        }

        getchar();
        if (isCharGinner('X', tablero))
            if (exes - 1 == os)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        else if (isCharGinner('O', tablero))
            if (exes == os)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        else if (exes == os || exes - 1 == os)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
