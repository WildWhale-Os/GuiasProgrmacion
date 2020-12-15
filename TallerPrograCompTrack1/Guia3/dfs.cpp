#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> grafo;
vector<int> visited;

bool Dfs(int v, int id)
{
    if (visited[v] != 0)
        return false;
    visited[v] = id;

    for (auto ves : grafo[v])
    {
        Dfs(ves, id);
    }
    return true;
}

int main(int argc, char const *argv[])
{
    //falta leer grafo 
    int id = 1;
    for(int i = 0; i < n; i++){
        boolean ncom = dfs(i, id);
        if(ncom) id++;
    }
    return 0;
}
