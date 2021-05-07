/*
 * leistung.c
 *
 * Programm
 *
 * Autor: S.Hirsig
 * Erstellt am: 03.12.2020
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "spo3_ain2.h"
#include "leistung.h"

static void ausgeben_benotet(int);

static void ausgeben_unbenotet(char);

bool leistung_einlesen(leistung* eingabe)
{
    int n;
    char s;

    if (scanf("%20s", eingabe->modulname) == 1) //20 um String 20 zu beschränken
    {

        char *x = eingabe->modulname;
        while ((x = strchr(x, '_')) != NULL)
        {
            *x = ' ';
        }
        if (scanf("%d", &n) == 1)
        {
            eingabe->i = n;
            eingabe->status = benotet;
            return true;
        }
        else if (scanf("%c", &s) == 1)
        {
            eingabe->s = s;
            eingabe->status = unbenotet;
            return true;
        } else {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void ausgeben(const leistung* eingabe)
{

    if (ist_ain2_modul(eingabe->modulname))
    {
        printf("%-*s\t", MAX_STRUCT_ARRAY_SIZE, eingabe->modulname);

        if (eingabe->status == 0)
        {
            ausgeben_benotet(eingabe->i);
        }
        else
        {
            ausgeben_unbenotet(eingabe->s);
        }
    }
    else
    {
        printf("Fehler: %s\n", eingabe->modulname);
    }
}

static void ausgeben_benotet(int s)
{
    printf("%c\t", 'L');
    if (ist_spo_note(s))
    {
        int a = s / 10;
        int b = s % 10;
        printf("%d,%d", a, b);
    }
    else
    {
        printf("Fehler: %d", s);
    }
    printf("\n");
}

static void ausgeben_unbenotet(char s)
{
    printf("%c\t", 'S');
    if (s == 'B')
    {
        printf("bestanden");
    }
    else if (s == 'N')
    {
        printf("nicht bestanden");
    }
    else
    {
        printf("Fehler: %c", s);
    }
    printf("\n");
}
