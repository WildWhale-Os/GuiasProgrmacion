#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int numLibros;
    while (cin >> numLibros)
    {
        int precios[numLibros];
        int total, diferecia = 200000000, min, max;
        for (int i = 0; i < numLibros; i++)
        {
            cin >> precios[i];
        }
        cin >> total;
        for (int i = 0; i < numLibros - 1; i++)
        {
            for (int j = i + 1; j < numLibros; j++)
            {
                if (precios[j] >= precios[i])
                {
                    if (precios[i] + precios[j] == total && precios[j] - precios[i] < diferecia)
                    {
                        min = precios[i];
                        max = precios[j];
                        diferecia = precios[j] - precios[i];
                    }
                }
                else if (precios[i] + precios[j] == total && precios[i] - precios[j] < diferecia)
                {
                    min = precios[j];
                    max = precios[i];
                    diferecia = precios[i] - precios[j];
                }
            }
        }
        cout << "Peter should buy books whose prices are " << min << " and " << max << "." << endl;
        cout << endl;
    }

    return 0;
}
