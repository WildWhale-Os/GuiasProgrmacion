def isPrime(num):
    if num == 1:
        return False
    for i in range(num+1):
        if i != 0:
            if num % i == 0:
                if i != 1 and i != num:
                    return False
    return True


def esUgly(num):
    if num == 1:
        return True
    for i in range(num + 1):
        if i != 0 and i != 1:
            if num % i == 0:
                if isPrime(i) and (i != 2 and i != 3 and i != 5):
                    return False
                elif not isPrime(i):
                    if i % 2 == 0:
                        return esUgly(int(i/2))
                    elif i % 3 == 0:
                        return esUgly(int(i/3))
                    elif i % 5 == 0:
                        return esUgly(int(i/5))
                    else:
                        return False
    return True


def uglyCounter(num):
    cont = 0
    init = 0
    while cont != num:
        init = init + 1
        if esUgly(init):
            cont = cont + 1

    return init


def main():
    print(uglyCounter(1500))


if __name__ == "__main__":
    main()
