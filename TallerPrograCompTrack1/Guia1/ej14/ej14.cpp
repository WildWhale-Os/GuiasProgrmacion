/*
Autor: Tomas Bravo
Solucion Propia.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i)
    {
        int numWord;
        cin >> numWord;
        getchar(); // limpiamos el buffer del teclado
        string palabras[numWord];
        for (int j = 0; j < numWord; ++j)
        {
            cin >> palabras[j];
        }
        string test;
        cin >> test;
        while (test != "END")
        {
            vector<string> anagram;
            for (int j = 0; j < numWord; j++)
            {
                if (test.length() == palabras[j].length())
                {
                    bool palindromo = true;
                    for (int k = 0; k < test.length(); ++k)
                    {
                        if (palabras[j].find(test.at(k)) == -1)
                        {
                            palindromo = false;
                            break;
                        }
                    }

                    if (palindromo)
                    {
                        anagram.push_back(palabras[j]);
                    }
                }
            }

            cout << "Anagrams for: " << test << endl;
            if (anagram.size() != 0)
            {
                for (int k = 0; k < anagram.size(); k++)
                {
                    cout << "  " << (1 + k) << ")"
                         << " " << anagram.at(k) << endl;
                }
            }
            else
            {
                cout << "No anagrams for: " << test << endl;
            }

            cin >> test;
        }
        if (i < cases - 1)
        {
            cout << endl;
        }
    }
    return 0;
}
