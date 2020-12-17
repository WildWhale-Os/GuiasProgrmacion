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
        set<int> cajas;
        for (int j = 0; j < num; j++)
        {
            int elem;
            cin >> elem;
            if (cajas.find(elem) == cajas.end())
            {
                cajas.insert(elem);
            }
            else
            {
                if (cajas.size() > mayor)
                {
                    mayor = cajas.size();
                }
                cajas.clear();
                
            }
        }
        cout << mayor << endl;
    }
    return 0;
}
