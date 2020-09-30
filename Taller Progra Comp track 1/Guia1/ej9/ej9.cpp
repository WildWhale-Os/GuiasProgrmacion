/*
Autor: Tomas Bravo
Solucion: Propia
*/

#include <bits/stdc++.h>

using namespace std;

/*
    I:1  V:5  X:10  L:50  C:100 D:500  M:1000
*/

int main(int argc, const char **argv)
{
    string entrada;
    while (cin >> entrada)
    {

        if (entrada.at(0) >= '0' && entrada.at(0) <= '9')
        {
            map<int, string> valores;
            valores.insert(pair<int, string>(1, "I"));
            valores.insert(pair<int, string>(5, "V"));
            valores.insert(pair<int, string>(10, "X"));
            valores.insert(pair<int, string>(50, "L"));
            valores.insert(pair<int, string>(100, "C"));
            valores.insert(pair<int, string>(500, "D"));
            valores.insert(pair<int, string>(1000, "M"));
            string salida;
            int elevado = entrada.size();
            for (int i = 0; i < entrada.size(); i++)
            {
                int num = (entrada[i] - '0') * pow(10, elevado - 1);
                int rep = num / pow(10, elevado - 1);
                switch (rep)
                {
                case 3:
                    salida.append(valores.at(pow(10, elevado - 1)));
                case 2:
                    salida.append(valores.at(pow(10, elevado - 1)));
                case 1:
                    salida.append(valores.at(pow(10, elevado - 1)));
                    break;
                case 4:
                    salida.append(valores.at(pow(10, elevado - 1)));
                case 5:
                    salida.append(valores.at(5 * pow(10, elevado - 1)));
                    break;
                case 6:
                    salida.append(valores.at(5 * pow(10, elevado - 1)));
                    salida.append(valores.at(pow(10, elevado - 1)));
                    break;
                case 7:
                    salida.append(valores.at(5 * pow(10, elevado - 1)));
                    salida.append(valores.at(pow(10, elevado - 1)));
                    salida.append(valores.at(pow(10, elevado - 1)));
                    break;
                case 8:
                    salida.append(valores.at(5 * pow(10, elevado - 1)));
                    salida.append(valores.at(pow(10, elevado - 1)));
                    salida.append(valores.at(pow(10, elevado - 1)));
                    salida.append(valores.at(pow(10, elevado - 1)));
                    break;
                case 9:
                    salida.append(valores.at(pow(10, elevado - 1)));
                    salida.append(valores.at(pow(10, elevado)));
                    break;
                }
                elevado--;
            }
            cout << salida << endl;
        }
        else
        {
            map<char, int> valores;
            valores.insert(pair<char, int>('I', 1));
            valores.insert(pair<char, int>('V', 5));
            valores.insert(pair<char, int>('X', 10));
            valores.insert(pair<char, int>('L', 50));
            valores.insert(pair<char, int>('C', 100));
            valores.insert(pair<char, int>('D', 500));
            valores.insert(pair<char, int>('M', 1000));
            int suma = 0;
            for (int i = 0; i < entrada.size(); i++)
            {
                if (i == entrada.size() - 1)
                    suma += valores.at(entrada.at(i));
                else if (valores.at(entrada.at(i)) < valores.at(entrada.at(i + 1)))
                {
                    suma += valores.at(entrada.at(i + 1)) - valores.at(entrada.at(i));
                    i++;
                }
                else
                {
                    suma += valores.at(entrada.at(i));
                }
            }

            cout << suma << endl;
        }
    }
    return 0;
}