/*
 * leistung.h
 *
 * Programm
 *
 * Autor: S.Hirsig
 * Erstellt am: 03.12.2020
 */

#ifndef LEISTUNG_H
#define LEISTUNG_H

#define MAX_STRUCT_ARRAY_SIZE 20

#include <stdbool.h>

enum leistungsart { benotet, unbenotet};

struct leistung //32 Byte Groß
{
    char modulname[MAX_STRUCT_ARRAY_SIZE + 1]; //24 Byte | +1 da \0
    union // 4 Byte
    {
        int i;
        char s;
    };
    enum leistungsart status; // 4 Byte
};
typedef struct leistung leistung;

bool leistung_einlesen(leistung*);

void ausgeben(const leistung*);

#endif
