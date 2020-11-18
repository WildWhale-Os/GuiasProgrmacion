#include <iostream>
#include <math.h>
using namespace std;

float Equation(float x, int p, int q, int r, int s, int t, int u)
{
    return p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

float Partision(float init, float fin, int p, int q, int r, int s, int t, int u)
{
    float x = (init + fin) / 2;
    if ((fin - init) / 2 >= 10e-7)
    {
        float result = Equation(x, p, q, r, s, t, u);
        if (fabs(Equation(init, p, q, r, s, t, u)) < 10e-6)
            return init;
        if (fabs(Equation(fin, p, q, r, s, t, u)) < 10e-6)
            return fin;
        if (result < 0)
        {
            if (result - Equation(x + (fin - init) / 2, p, q, r, s, t, u) > 0)
                return Partision(init, x, p, q, r, s, t, u);
            else
                return Partision(x, fin, p, q, r, s, t, u);
        }
        if (result > 0)
        {
            if (result - Equation(x + (fin - init) / 2, p, q, r, s, t, u) > 0)
                return Partision(x, fin, p, q, r, s, t, u);
            else
                return Partision(init, x, p, q, r, s, t, u);
        }
        if (fabs(result) < 10e-6)
            return x;
    }
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    int p, q, r, s, t, u;
    while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF)
    {
        float result = Partision(0, 1, p, q, r, s, t, u);
        if (fabs(result + 1) >= 10e-6)
        {
            printf("%.4f\n", result);
        }
        else
            cout << "No solution" << endl;
    }

    return 0;
}
