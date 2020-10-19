import sys
import numpy as np


def algortmo(num):
    cont = 1
    while True:
        if num == 1:
            break
        if num % 2 == 0:
            num = num/2
        else:
            num = 3*num + 1
        cont = cont + 1
    return cont


def contadorIteraciones(inf, sup):
    cont = -1
    while inf <= sup:
        tem = algortmo(inf)
        if tem > cont:
            cont = tem
        inf = inf + 1
    return cont


def main():
    arreglo = np.array([],dtype=int)
    while True:
        try:
            num1,num2 = map(int, sys.stdin.readline().split(" "))
            mayor = contadorIteraciones(num1, num2) if (num1 < num2) else contadorIteraciones(num2, num1)
            np.append(arreglo,[num1 , num2, mayor])
            print(num1 , num2, mayor)
        except EOFError as error:
            input()
            for i in arreglo:
                print(arreglo[i])
            break

if __name__ == "__main__":
    main()