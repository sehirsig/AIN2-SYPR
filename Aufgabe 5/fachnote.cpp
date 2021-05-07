/*
 * fachnote.cpp
 *
 * Entitätenklasse fachnote
 *
 * Autir: S.Hirsig
 * Erstellt am: 01.01.2021
 */
 
 #include "fachnote.h"
 #include <stdexcept>
 
 fachnote::fachnote(const std::string &s, const benotung &d)
 : fach(s), note(d)
 { 
    if (s.length() == 0)
    {
        throw std::invalid_argument("Unzulaessiges Fach");
    }
 }
