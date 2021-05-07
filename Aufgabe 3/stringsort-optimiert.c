/*
 * stringsort.optimiert.c
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

void bubblesort(void* array, size_t groesse, size_t laengeeinzeln, int (*compare)(const void *, const void *));

int main(int argc, char *argv[])
{
    int n, maxstringlength;
    char *endstring, *matrix;



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

    maxstringlength = strlen(argv[1]) + 1;

    //---------------------------------------------------------- Strings würfeln
    matrix = (char*) malloc(n * maxstringlength);
    if (matrix == NULL)
    {
        printf("Speicherreservierung endstring fehlgeschlagen!\n");
        return 1;
    }

    endstring = (char*) malloc(sizeof (char) + (n * maxstringlength));
    if (endstring == NULL)
    {
        printf("Speicherreservierung endstring fehlgeschlagen!\n");
        free(matrix);
        return 1;
    }

    printf("Unsortiertes Array:\n");

    for (int i = 0; i < n; ++i)
    {
        int tempnumber = rand() % n;
        sprintf(matrix + (i * maxstringlength), "%d", tempnumber);
        printf("%s ", matrix + i * maxstringlength);
    }
    //---------------------------------------------------------- Strings sortieren

    bubblesort(matrix, n, maxstringlength, (int(*)(const void*, const void*))strcmp);

    //---------------------------------------------------------- Strings ausgeben

    printf("\nSortiertes Array: \n");

    strcpy(endstring, "\0");
    strcat(endstring, matrix);

    for (int i = 1; i < n; i++)
    {
        if (strcmp(matrix + i * maxstringlength, ((matrix + i * maxstringlength) - maxstringlength)) == 0)
        {
            strcat(endstring, "*");
        }
        else
        {
            strcat(endstring, " ");
            strcat(endstring, matrix + i * maxstringlength);
        }

    }

    printf("%s\n", endstring);

    free(matrix);
    free(endstring);
    return 0;
}

void bubblesort(void* array, size_t groesse, size_t laengeeinzeln, int (*compare)(const void *, const void*))
{
    char* a = (char*) array;
    char* tmp = (char*) malloc(laengeeinzeln);
    if (tmp == NULL) {
        printf("Speicherreservierung endstring fehlgeschlagen!\n");
        exit(1);
    }
    for (int i = groesse; i > 0; i--)
    {
        for (int j = 0; j < i - 1; ++j)
        {
            char* links = (a + j * laengeeinzeln);
            char* rechts = ((a + j * laengeeinzeln) + laengeeinzeln);
            if (compare(links, rechts) > 0)
            {
                memcpy(tmp, rechts, strlen(rechts) + 1);
                memcpy(rechts, links, strlen(links) + 1);
                memcpy(links, tmp, strlen(tmp) + 1);
            }
        }
    }
    free(tmp);
}
*/
