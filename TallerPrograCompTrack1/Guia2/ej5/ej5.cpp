#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int C = 67, I = 73, R = 82, U = 85, E = 69;
struct Participante
{
    int resueltos[9] = {0};
    int tiempo = 0;
};


int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        map<int,Participante>board;
        int participant, time, problem, resutlado;
        while (cin >> participant >> problem >> time >> resutlado)
        {
            cout << participant << " " << problem << " " << time << " " << resutlado << endl;
            if (board.find(participant) != board.end())
            {
                Participante aux = board.at(participant);
                if (aux.resueltos[problem] == 0 && resutlado == I)
                {
                    aux.tiempo += 20;
                }
                else if (resutlado == C)
                {
                    aux.resueltos[problem] = 1;
                }
                aux.tiempo += time;
                
                
            }else
            {
                Participante aux;
                if (resutlado == I) aux.tiempo += 20;
                else if(resutlado == C) aux.resueltos[problem] = 1;
                aux.tiempo += time;

                board[participant] = aux;
            }   
        }

        int elem = board.
    }
    
    return 0;
}
