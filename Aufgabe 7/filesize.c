/*
 * filesize.c
 *
 * Zählt Filenames und wertet sie aus.
 *
 * Author: S.Hirsig
 * Erstellt am: 25.01.2021
 *
 */

#define MAX_ARRAY_SIZE 20

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <locale.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc < 2)                           // Aufruf ohne Kommandozeilenargumente
    {
        int count = 0;
        ssize_t test;
        char bufstring[MAX_ARRAY_SIZE + 1];
        while ((test = read(STDIN_FILENO, bufstring, 1)) == 1) //"Enter" Taste wird mitgerechnet
        {
            count++;
            
        }
        if (test == -1)
        {
            perror("read()");
            return -1;
        }
        printf("%d Bytes\n", (int)count);

    }
    else                                    // Aufruf mit Kommandozeilenargumente
    {
        for (int i = 1; i < argc; ++i)
        {
            struct stat file_stat;

            if ( stat(argv[i], &file_stat) != 0)
            {
                perror("stat()");
            }
            else
            {
                printf("%ld\t%s\n", (long)file_stat.st_size, argv[i]);
            }
        }
    }

    return 0;
}
