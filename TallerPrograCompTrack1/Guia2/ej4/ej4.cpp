#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    while (cin >> num)
    {
        int numeros[num], resultado = INT32_MAX, menor = INT32_MAX, mayor = 0, repeticiones = 0;
        vector<int> opciones;
        for (int i = 0; i < num; i++)
        {
            cin >> numeros[i];
            if (numeros[i] > mayor)
                mayor = numeros[i];
        }
        for (int j = 0; j <= mayor; j++)
        {
            int aux = 0;
            for (int i = 0; i < num; i++)
                aux += abs(numeros[i] - j);
            if (aux < resultado)
            {
                opciones.clear();
                resultado = aux;
                opciones.push_back(j);
                menor = j;
            }
            else if (aux == resultado)
            {
                opciones.push_back(j);
                if (j < menor)
                    menor = j;
            }

        }

        for (int i : numeros)
            if (i == menor)
                repeticiones++;
        cout << menor << " " << repeticiones << " " << opciones.size() << endl;
    }

    return 0;
}
