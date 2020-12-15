#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int num, caja = 0, mayor = -1;
        cin >> num;
        vector<set<int>> cajas;
        set<int> aux;
        cajas.push_back(aux);
        for (int j = 0; j < num; j++)
        {
            int elem;
            cin >> elem;
            if (cajas.at(caja).find(elem) == cajas.at(caja).end())
            {
                cajas.at(caja).insert(elem);
            }
            else
            {
                set<int> nueva;
                cajas.push_back(nueva);
                caja++;
            }
        }
        for (int j = 0; j < cajas.size(); j++)
        {
            if (cajas.at(j).size() > mayor)
                mayor = cajas.at(j).size();
        }
        cout << mayor << endl;
    }
    return 0;
}
