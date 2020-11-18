/*
Autor: Tomas Bravo
Solucion : Propia
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    getchar();
    for (int i = 0; i < cases; i++)
    {
        double result = 0;
        int num1, num2;
        bool full1 = false, full2 = false;
        string aux, num = "";
        getline(cin, aux);
        for (int i = 0; i < aux.size(); i++)
        {
            if (aux.at(i) >= '0' && aux.at(i) <= '9')
            {
                num += aux.at(i);
            }
            else
            {
                if (!full1)
                {
                    num1 = stoi(num);
                    num.clear();
                    full1 = true;
                }
                else if(!full2 and num >= "0" and num <= "9")
                {
                    num2 = stoi(num);
                    num.clear();
                    full2 = true;
                }

            }
        }

        if(full1) result += num1 *0.5;
        if(full2) result += num2 * 0.05;
        if(result - (int)result <= 10e-6)
            cout << "Case " << i + 1 << ": " << (int)result << endl;
        else
            cout << "Case " << i + 1 << ": " << result << endl;
    }
    return 0;
}
