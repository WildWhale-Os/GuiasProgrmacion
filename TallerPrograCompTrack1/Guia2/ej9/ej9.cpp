#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int lastCard;
    cin >> lastCard;
    while (lastCard != 0)
    {
        queue<int> mazo;
        vector<int> descarted;
        descarted.reserve(lastCard - 1);
        for (int i = 1; i <= lastCard; i++)
            mazo.push(i);
        while (mazo.size() >= 2)
        {
            descarted.push_back(mazo.front());
            mazo.pop();
            int aux = mazo.front();
            mazo.pop();
            mazo.push(aux);
        }
        cout << "Discarded cards:";
        if (descarted.size() == 0)
        {
            cout << endl;
        }
        
        for (int i = 0; i < descarted.size(); i++)
        {
            if (descarted.at(i) == descarted.back())
            {
                cout << " " << descarted.back() << endl;
            }
            else
            {
                cout << " " << descarted.at(i) << ",";
            }
        }
        cout << "Remaining card: " << mazo.front() << endl;
        cin >> lastCard;
    }
    return 0;
}
