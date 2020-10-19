#include <bits/stdc++.h>

using namespace std;

typedef struct 
{
    string prefijo;
    string localidad;
    int precio;
} Destino;


int main(int argc, char const *argv[])
{
    string linea;
    getline(cin, linea);
    vector<Destino> prefijos;
    while (linea != "000000")
    {
        string al;
        Destino aux;
        linea =  linea.replace('$',"\n");
        istringstream ss(linea);
        ss >> aux.prefijo;
        ss >> aux.localidad;
        ss >> aux.precio;
        getline(ss, al);
        prefijos.push_back(aux);
    }

    for (int i = 0; i < prefijos.size(); i++)
    {
        cout << prefijos[i].prefijo << endl;
        cout << prefijos[i].localidad << endl;
        cout << prefijos[i].precio << endl;
        cout << endl;
    }
    
    return 0;
}
