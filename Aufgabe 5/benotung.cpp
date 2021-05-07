/*
 * benotung.cpp
 *
 * Wertklasse benotung
 *
 * Autor: S.Hirsig
 * Erstellt am: 01.01.2021
 */
 #include "benotung.h"
 #include <stdexcept>
 #include <iostream>
 
 int benotung::int_value() const
 {
    return this->note;
 }
 
 bool benotung::ist_bestanden() const
 {
    return this->note <= 40;
 }
 
 const benotung benotung::beste = benotung(10);
 
 const benotung benotung::schlechteste = benotung(50);
 
 
 benotung::benotung(int n)
 : note(n)
 { 
    switch(n) {
        case 10:
        case 13:
        case 17:
        case 20:
        case 23:
        case 27:
        case 30:
        case 33:
        case 37:
        case 40:
        case 50:
            this->note = n;
            break;
        default: 
            //this->note = null;
            std::cout << n;
            throw std::invalid_argument("unzulässige Note");
            break;
        }
 }
 
 bool operator==(benotung a, benotung b)
 {
    return a.note == b.note;
 }
