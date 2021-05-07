/*
 * aufgabe1.c
 *
 * Aufgabe 1 in Systemprogrammierung.
 *
 * Autor: Sebastian Hirsig
 * Erstellt am: 19.10.2020
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int intzahl = 123;
    short shortintzahl = 123;
    long longintzahl = 123L;
    long long longlongintzahl = 123LL;
    unsigned int uintzahl = 123;
    unsigned short ushortintzahl = 123;
    unsigned long ulongintzahl = 123L;
    unsigned long long ulonglongintzahl = 123LL;
    float floatzahl = 1.23F;
    double doublezahl = 12.3;
    long double longdoublezahl = 12.3L;
    char zeichen = 'a';
    signed char sbyte = 35;
    unsigned char ubyte = 80;
    bool abool = true;
    const char* charstar = "Hallo";

    printf("%p | %2zu | %13s | %17s | %d \n", (void*) &intzahl, sizeof(intzahl), "int", "intzahl", intzahl);
    printf("%p | %2zu | %13s | %17s | %hd \n", (void*) &shortintzahl, sizeof(shortintzahl), "short", "shortintzahl", shortintzahl);
    printf("%p | %2zu | %13s | %17s | %ld \n", (void*) &longintzahl, sizeof(longintzahl), "long", "longintzahl", longintzahl);
    printf("%p | %2zu | %13s | %17s | %lld \n", (void*) &longlongintzahl, sizeof(longlongintzahl), "long long", "longlongintzahl", longlongintzahl);
    printf("%p | %2zu | %13s | %17s | %u \n", (void*) &uintzahl, sizeof(uintzahl), "uint", "uintzahl", uintzahl);
    printf("%p | %2zu | %13s | %17s | %hu \n", (void*) &ushortintzahl, sizeof(ushortintzahl), "ushort", "ushortintzahl", ushortintzahl);
    printf("%p | %2zu | %13s | %17s | %lu \n", (void*) &ulongintzahl, sizeof(ulongintzahl), "ulong", "ulongintzahl", ulongintzahl);
    printf("%p | %2zu | %13s | %17s | %llu \n", (void*) &ulonglongintzahl, sizeof(ulonglongintzahl), "ulonglong", "ulonglongintzahl", ulonglongintzahl);
    printf("%p | %2zu | %13s | %17s | %f \n", (void*) &floatzahl, sizeof(floatzahl), "float", "floatzahl", floatzahl);
    printf("%p | %2zu | %13s | %17s | %f \n", (void*) &doublezahl, sizeof(doublezahl), "double", "doublezahl", doublezahl);
    printf("%p | %2zu | %13s | %17s | %Lf \n", (void*) &longdoublezahl, sizeof(longdoublezahl), "longdouble", "longdoublezahl", longdoublezahl);
    printf("%p | %2zu | %13s | %17s | %c \n", (void*) &zeichen, sizeof(zeichen), "char", "zeichen", zeichen);
    printf("%p | %2zu | %13s | %17s | %hhd \n", (void*) &sbyte, sizeof(sbyte), "signed char", "sbyte", sbyte);
    printf("%p | %2zu | %13s | %17s | %hhu \n", (void*) &ubyte, sizeof(ubyte), "unsigned char", "ubyte", ubyte);
    printf("%p | %2zu | %13s | %17s | %d \n", (void*) &abool, sizeof(abool), "_Bool", "abool", abool);
    printf("%p | %2zu | %13s | %17s | %s \n", (void*) &charstar, sizeof(charstar), "char*", "charstar", charstar);

    printf("\nPC-Datenmodell: ");
    if ((sizeof(intzahl) == 4) == (sizeof(longintzahl) == 4) && (sizeof(charstar) == 4))
    {
        printf("ILP32\n");
    }
    else if ((sizeof(intzahl) == 4) && (sizeof(longintzahl) == 8) && (sizeof(charstar) == 8))
    {
        printf("LP64\n");
    }
    else if ((sizeof(intzahl) == 4) == (sizeof(longintzahl) == 4) && (sizeof(charstar) == 8) && (sizeof(longlongintzahl) == 8))
    {
        printf("LLP64\n");
    }
    else
    {
        printf("ERROR\n");
    }

    return 0;
}
