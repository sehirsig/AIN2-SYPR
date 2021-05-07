/*
 * benotung.h
 *
 * Wertklasse benotung
 *
 * Autor: S.Hirsig
 * Erstellt am: 01.01.2021
 */
#ifndef BENOTUNG_H
#define BENOTUNG_H

class benotung final
{
private:
    int note;


public:
    static const benotung beste;
    static const benotung schlechteste;

    benotung() = default;
    explicit benotung(int t);

    int int_value() const;
    bool ist_bestanden() const;

    friend bool operator==(benotung, benotung);

};


#endif
