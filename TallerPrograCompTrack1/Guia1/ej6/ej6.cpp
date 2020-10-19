/*
Autor : Tomas Bravo
Solucion: Propia
*/
#include <bits/stdc++.h>

using namespace std;

bool isPrime(long &value);
vector<long> PrimeDescomp(long num);

int main(int argc, char const *argv[])
{
    long num;
    cin >> num;
    while (num != 0)
    {
        if (num == 1)
            cout << num << " = ";
        else
        {
            vector<long> salida = PrimeDescomp(num);
            for (int i = 0; i < salida.size(); i++)
            {
                if (i == 0)
                    cout << num << " = " << salida[i];
                else
                    cout << " x " << salida[i];
            }
        }

        cout << endl;
        cin >> num;
    }
    return 0;
}




vector<long> PrimeDescomp(long num)
{
    vector<long> salida;
    if (num >= 0)
    {
        while (num % 2 == 0)
        {
            salida.push_back(2);
            num /= 2;
        }

        for (long i = 3; i <= sqrt(num); i += 2)
        {
            while (num % i == 0)
            {
                salida.push_back(i);
                num /= i;
            }
        }
        
        if(num > 2)
            salida.push_back(num);

    }
    else
    {
        salida.push_back(-1);
        num *=-1;
        while (num % 2 == 0)
        {
            salida.push_back(2);
            num /= 2;
        }

        for (long i = 3; i <= sqrt(num); i += 2)
        {
            while (num % i == 0)
            {
                salida.push_back(i);
                num /= i;
            }
        }
        
        if(num > 2)
            salida.push_back(num);
    }

    return salida;
}
