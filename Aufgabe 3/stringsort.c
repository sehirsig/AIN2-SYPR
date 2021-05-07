/*
 * stringsort.c
 *
 * Aufgabe 3 in Systemprogrammierung.
 *
 * Autor: Sebastian Hirsig
 * Erstellt am: 20.11.2020
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void bubblesort(char** a, const int size);

int main(int argc, char *argv[])
{
    int n, length;
    char** stringArray;
    char* endstring;

    srand((unsigned int) time(NULL));

    //---------------------------------------------------------- Arraygroesse bestimmen
    if (argc != 2)
    {
        printf("Usage: Stringsort.c element-count\n");
        return -1;
    }
    n = atoi(argv[1]);
    if (n < 1)
    {
        printf("Anzahl muss mindestens 1 sein\n");
        return -1;
    }

    length = strlen(argv[1]);

    //---------------------------------------------------------- Strings würfeln

    endstring = (char*) malloc(sizeof (char) + (n * (length + 1)));
    if (endstring == NULL)
    {
        printf("Speicherreservierung endstring fehlgeschlagen!\n");
        return 1;
    }
    stringArray = (char**) malloc(n * sizeof (char*));
    if (stringArray == NULL)
    {
        printf("Speicherreservierung stringArray fehlgeschlagen!\n");
        free(endstring);
        return 1;
    }

    printf("Unsortiertes Array:\n");

    for (int i = 0; i < n; ++i)
    {
        int tempnumber = rand() % n;
        char* str;
        str = (char*) malloc(length + 1);
        if (str == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(stringArray[j]);
            }
            printf("Speicherreservierung stringArray fehlgeschlagen!\n");
            free(endstring);
            free(stringArray);
            return 1;
        }
        sprintf(str, "%d", tempnumber);
        stringArray[i] = str;
        printf("%s ", stringArray[i]);
    }
    //---------------------------------------------------------- Strings sortieren

    bubblesort(stringArray, n);

    //---------------------------------------------------------- Strings ausgeben
    printf("\nSortiertes Array: \n");

    strcpy(endstring, "\0");
    strcat(endstring, stringArray[0]);

    for (int i = 1; i < n; i++)
    {
        if (strcmp(stringArray[i], stringArray[i - 1]) == 0)
        {

            strcat(endstring, "*");
        }
        else
        {
            strcat(endstring, " ");
            strcat(endstring, stringArray[i]);
        }

    }


    for (int i = 0; i < n; i++)
    {
        free(stringArray[i]);
    }
    printf("%s\n", endstring);

    free(stringArray);
    free(endstring);
    return 0;
}

void bubblesort(char** a, const int size)
{
    for (int i = size; i > 0; i--)
    {
        for (int j = 0; j < i - 1; ++j)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                char* tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}
