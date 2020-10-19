from sys import stdin
from time import sleep


def CalcularPoly(poly, valor):
    result = 0
    exponente = 0
    for i in reversed(poly):
        result = result + pow(valor, exponente)*i
        exponente = exponente + 1
    return result


def main():

    while True:
        try:
            entrada = []
            lineas = []
            linea1 = input()
            linea2 = input()
            linea1 = linea1.split(" ")
            linea2 = linea2.split(' ')

            for i in range(len(linea1)):
                linea1[i] = int(linea1[i])
            entrada.append(linea1)
            for i in range(len(linea2)):
                linea2[i] = int(linea2[i])
            entrada.append(linea2)
            
            pos = 0
            posnum = pos + 1
            sleep(0.5)
            while posnum < len(entrada):
                print(" ".join(str(CalcularPoly(entrada[pos], i)) for i in entrada[posnum]))
                pos = pos + 2
                posnum = pos + 1

        except:
            break

if __name__ == "__main__":
    main()
