/*
 * bubblesort.c
 *
 * Aufgabe 2 in Systemprogrammierung.
 *
 * Autor: Sebastian Hirsig
 * Erstellt am: 29.10.2020
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int n;
    int *a;
    srand((unsigned int) time(NULL));
    //---------------------------------------------------------- Arraygroesse einlesen
    if (argc != 2)
    {
        printf("Usage: bubblesort element-count\n");
        return -1;
    }

    n = atoi(argv[1]);

    //---------------------------------------------------------- Zahlen einlesen
    a = (int*) malloc(n * sizeof (int));
    if (a == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }

    printf("Bitte %d ganze Zahlen eingeben: \n", n);

    for (int i = 0; i < n; ++i)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            a[i] = rand();
            printf("%d\n", a[i]);
        }

    }
    printf("\n");
    //---------------------------------------------------------- Zahlen sortieren
    for (int i = n; i > 1; --i)
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                //Werte tauschen
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    //---------------------------------------------------------- Zahlen ausgeben
    printf("Sortierte Zahlenfolge: \n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", a[i]);
    }


    free(a);
    return 0;
}
