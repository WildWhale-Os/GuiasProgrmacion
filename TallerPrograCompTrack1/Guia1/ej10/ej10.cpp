#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int rows, col;
    cin >> rows;
    cin >> col;
    while (rows != 0 && col != 0)
    {

        int maze[rows][col];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> maze[i][j];
            }
        }

        cin >> rows;
        cin >> col;
    }
    return 0;
}
