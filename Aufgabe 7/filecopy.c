/*
 * filecopy.c
 *
 * Kopiert erstgenannte Datei in zweitgenannte
 *
 * Author: S.Hirsig
 * Erstellt am: 25.01.2021
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

void cleaner(unsigned char* buf, int src, int dst);

int main(int argc, char *argv[])
{
    if (setlocale(LC_MESSAGES, "de_DE.UTF-8") == 0)
    {
        fprintf(stderr, "Locale(): German Language not installed!\n");
        return -1;
    }

    if (argc == 3)                                                     // Korrekte Eingabe
    {
        struct stat file_statsrc;
        int src, dst;
        unsigned char *buffer;
        size_t size;
        ssize_t size_read;

        /* Quelle Öffnen */
        src = open(argv[1], O_RDONLY);
        if (src == -1)
        {
            perror("open()");
            return -1;
        }

        /* Quellen Infos beziehen*/
        if (fstat(src, &file_statsrc) != 0)                         		// Fehler
        {
            perror("fstat()");
            return -1;
        }

        /*Zieldatei erstellen*/
        dst = creat(argv[2], file_statsrc.st_mode);
        if (dst == -1)
        {
            perror("creat()");
            return -1;
        }

        /*Kopiervorgang*/
        size = (size_t)file_statsrc.st_size;
        buffer = malloc(size);
        if (buffer == NULL)
        {
            fprintf(stderr, "malloc(): failed");
            cleaner(buffer, src, dst);
            return -1;
        }

        size_read = read(src, buffer, size);
        if (size_read == -1)
        {
            perror("read()");
            cleaner(buffer, src, dst);
            return -1;
        }

        if ((size_t)size_read < size)
        {
            fprintf(stderr, "read(): error couldn't read full file");
            cleaner(buffer, src, dst);
            return -1;
        }

        if (write(dst, buffer, (size_t)size_read) == -1)
        {
            perror("write()");
            cleaner(buffer, src, dst);
            return -1;
        }

        cleaner(buffer, src, dst);

    }
    else                                                                // Fehlerbehandlung: Zu wenig / viele Argumente
    {
        printf("Usage: filecopy source_file target_file\n");
        return -1;
    }

    return 0;
}


void cleaner(unsigned char* buf, int src, int dst)
{
    free(buf);
    close(src);
    close(dst);
}
