#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    getchar();
    getchar();
    for (int i = 0; i < cases; i++)
    {
        map<string, float> especies;
        string plant;
        cout << fixed;
        cout.precision(4);
        getline(cin, plant);
        while (!plant.empty())
        {
            if (especies.find(plant) != especies.end())
            {
                float cant = especies[plant];
                especies.erase(plant);
                especies[plant] = cant + 1;
            }
            else
                especies[plant] = 1;
            getline(cin, plant);
        }
        float total = 0;
        for (auto const &j : especies)
            total += especies[j.first];
        for (auto const &j : especies)
        {
            cout << j.first << " " << (especies[j.first] / total) * 100 << endl;
        }

        if (i < cases - 1)
            cout << endl;
    }
    return 0;
}
