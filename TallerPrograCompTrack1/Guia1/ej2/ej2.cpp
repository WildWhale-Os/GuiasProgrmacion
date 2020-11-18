/*
Autor: Tomas Bravo
Solucion : Propia
*/

#include <iostream>
using namespace std;

int main()
{
	int uglyNumbers[1500] = {1}, multi2 = 0, multi3 = 0, multi5 = 0, menor;
	for (int i = 1; i < 1500; i++)
	{
		while (uglyNumbers[multi2] * 2 <= uglyNumbers[i - 1])
			multi2++;
		while (uglyNumbers[multi3] * 3 <= uglyNumbers[i - 1])
			multi3++;
		while (uglyNumbers[multi5] * 5 <= uglyNumbers[i - 1])
			multi5++;
		menor = uglyNumbers[multi2] * 2;
		if (uglyNumbers[multi3] * 3 < menor)
			menor = uglyNumbers[multi3] * 3;
		if (uglyNumbers[multi5] * 5 < menor)
			menor = uglyNumbers[multi5] * 5;
		uglyNumbers[i] = menor;
	}
	cout << "The 1500'th ugly number is " << uglyNumbers[1499] << "." << endl;
	return 0;
}