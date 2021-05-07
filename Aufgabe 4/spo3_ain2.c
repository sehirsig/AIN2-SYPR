/*
 * spo3_ain2.c
 *
 * Programm
 *
 * Autor: S.Hirsig
 * Erstellt am: 03.12.2020
 */

#include <string.h>
#include "spo3_ain2.h"

bool ist_spo_note(int m)
{
    static int zulaessig[] = { 10, 13, 17, 20, 23, 27, 30, 33, 37, 40, 50 };
    static const int array_size = (int) (sizeof zulaessig / sizeof * zulaessig);

    for (int i = 0; i < array_size; ++i)
    {
        if (m == zulaessig[i])
        {
            return true;
        }
    }

    return false;
}

bool ist_ain2_modul(const char *m)
{
    static const char *stringarray[] = { "Mathematik 2", "Stochastik", "Programmiertechnik 2", "Systemprogrammierung", "Rechnerarchitekturen" };
    static const int array_size = (int) (sizeof stringarray / sizeof * stringarray);

    for (int i = 0; i < array_size; ++i)
    {
        if (strcmp(m, stringarray[i]) == 0)
        {
            return true;
        }
    }

    return false;
}
