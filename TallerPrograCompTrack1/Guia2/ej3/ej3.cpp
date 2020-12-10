#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Arreglo
{
    int datos[3];
    vector<pair<int, int>> bound;
};

int calculo(Arreglo aux, int num[])
{
    int direccion = 0, dim = aux.datos[2], size = aux.datos[1], base = aux.datos[0];
    int ccero = base;
    for (int i = 0; i < dim; i++)
    {
        int c = size;
        for (int j = i; j < dim - 1; j++)
            c *= (aux.bound.at(j + 1).second - aux.bound.at(j + 1).first) + 1;
        direccion += num[i] * c;
        ccero -= (c * aux.bound.at(i).first);
    }
    direccion += ccero;
    return direccion;
}

int main()
{
    int arrays, references;
    cin >> arrays >> references;
    map<string, Arreglo> datos;
    for (int i = 0; i < arrays; i++)
    {
        Arreglo aux;
        string nombre;
        cin >> nombre;
        cin >> aux.datos[0] >> aux.datos[1] >> aux.datos[2];
        for (int j = 0; j < aux.datos[2]; j++)
        {
            int upper, low;
            cin >> low >> upper;
            aux.bound.push_back(pair<int, int>(low, upper)); 
        }
        datos[nombre] = aux;
        getchar();
    }
    for (int i = 0; i < references; i++)
    {
        string nombre;
        cin >> nombre;
        cout << nombre << "[";
        Arreglo aux = datos.at(nombre);
        int numeros[aux.datos[2]];
        for (int j = 0; j < aux.datos[2]; j++){
            cin >> numeros[j];
            if(j < (aux.datos[2] -1))
                cout << numeros[j] <<", "; 
            else
                cout << numeros[j] << "]";  
        }
        cout << " = " << calculo(aux,numeros) << endl;
        getchar();
    }
}