/*

Autor: Tomas Bravo.
Tipo de Solucion: Propia

Escribe la representación en binario, octal y hexadecimal de los siguientes números en base 10:
- 29
- 131
- 2048
- 121817
- 4000000001
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("-------------------------------------------------\n");
    printf("El representacion del numero 29 en forma :\n"); // representacion es del numero 29 en base:
    printf("Hexadecimal es %X\n", 29);                      // 16 (hexadecimal)
    printf("Octal es %o\n", 29);                            // 8 (octal)
    printf("Binario es 11101\n");                           // 2 (binario)
    printf("-------------------------------------------------\n");
    printf("El representacion del numero 131 en forma :\n"); // representacion es del numero 131 en base:
    printf("Hexadecimal es %X\n", 131);                      // 16 (hexadecimal)
    printf("Octal es %o\n", 131);                            // 8 (octal)
    printf("Binario es 1000011\n");                          // 2 (binario)
    printf("-------------------------------------------------\n");
    printf("El representacion del numero 2048 en forma :\n"); // representacion es del numero 2048 en base:
    printf("Hexadecimal es %X\n", 2048);                      // 16 (hexadecimal)
    printf("Octal es %o\n", 2048);                            // 8 (octal)
    printf("Binario es 100000000000\n");                      // 2 (binario)
    printf("-------------------------------------------------\n");
    printf("El representacion del numero 121817 en forma :\n"); // representacion es del numero 121817 en base:
    printf("Hexadecimal es %X\n", 121817);                      // 16 (hexadecimal)
    printf("Octal es %o\n", 121817);                            // 8 (octal)
    printf("Binario es 11101101111011001");                     // 2 (binario)
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("El representacion del numero 4000000001 en forma :\n"); // representacion es del numero 4000000001 en base:
    printf("Hexadecimal es %lX\n", 4000000001);                     // 16 (hexadecimal)
    printf("Octal es %lo\n", 4000000001);                           // 8 (octal)
    printf("Binario es 11101110011010110010100000000001\n");        // 2 (binario)
    printf("-------------------------------------------------\n");

    return 0;
}