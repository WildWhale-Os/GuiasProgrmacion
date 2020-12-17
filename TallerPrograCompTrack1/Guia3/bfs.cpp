#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> grafo; // lists de adyacencia
int n;                     // numero de nodos
vector<bool> enCola;       // list de nodos visitados
vector<int> padres;        // vector de padres

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    padres.resize(n, -1);
    enCola.resize(n, false);
    enCola[s] = true;
    while (not q.empty())
    {
        int node = q.front();
        q.pop();

        for (int hijo : grafo.at(node))
        {
            if (not enCola[hijo])
            {
                q.push(hijo);
                enCola[hijo] = true;
                padres[hijo] = node;
            }
        }
    }
}

void recorrerCamino(int desde)
{
    int tmp = desde;
    cout << desde << " -> ";
    while (padres[tmp] != -1)
    {
        cout << padres[tmp] << " -> ";
        tmp = padres[tmp];
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> n >> m;
    grafo.resize(n);
    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        grafo[n1].push_back(n2);
        grafo[n2].push_back(n1); // en case de grafo no dirigida, si es dirigido esta linea no se coloca
    }

    bfs(0);
    recorrerCamino(4);

    return 0;
}
