#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    getchar();                                                  //limpiar buffer
    for (int i = 0; i < cases; i++)
    {
        string aux;
        string linea;
        int num1, num2;
        float peso = 0.0f;
        getline(cin, linea);
        istringstream data(linea);
        data >> num1;
        peso += (float)num1 * 0.5f;
        data >> aux;
        if (data >> num2)
            peso += (float)num2 * 0.05f;
        if (peso - (int)peso < 10e-6)
            cout << "Case " << (i + 1) << ": " << trunc(peso) << endl;
        else
            cout << "Case " << (i + 1) << ": " << peso << endl;
    }
    return 0;
}
