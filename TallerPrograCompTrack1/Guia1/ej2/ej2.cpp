#include <iostream>

bool isUgly(int num)
{
    return (num == 1 || num % 2 == 0 || num % 3 == 0 || num % 5 == 0);
}

int whichUglyNumber(int pos)
{
    int cont = 0;
    int num = 0;
    while (cont <= pos )
    {
        if (isUgly(num))
            cont++;
        num++;
    }
    return num;
}

int main(int argc, char const *argv[])
{
    std::cout << whichUglyNumber(1500) << std::endl;

    return 0;
}
