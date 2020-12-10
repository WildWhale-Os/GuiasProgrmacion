#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int size, pos, min = 0;
        queue<int> cola;
        int priority[size];
        cin >> size >> pos;
        for (int j = 0; j < size; j++)
        {
            cin >> priority[j];
            cola.push(priority[j]);
        }
        bool track = true;
        while (track)
        {
            int aux = cola.front();
            cola.pop();
            if (pos == 0)
            {
                for (int j = 1; j < size; j++)
                {
                    if (aux < priority[j])
                    {
                        cola.push(aux);
                        pos = cola.size() - 1;
                        break;
                    }
                }
                if (pos == 0)
                {
                    min++;
                    track = false;
                }
            }
            else
            {
                int j;
                for (j = 1; j < size; j++)
                {
                    if (aux < priority[j])
                    {
                        cola.push(aux);
                        break;
                    }
                }
                if(j >= size - 1) min ++;
                pos--;
            }
        }

        cout << min << endl;
    }
}