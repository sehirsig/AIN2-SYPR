/*
 * fachnote.h
 *
 * Entitätenklasse fachnote
 *
 * Autir: S.Hirsig
 * Erstellt am: 01.01.2021
 */

#ifndef FACHNOTE_H
#define FACHNOTE_H

#include "benotung.h"
#include <string>

class fachnote final
{
private:


public:
    const std::string fach;
    const benotung note;

    fachnote(const std::string&, const benotung&);
    ~fachnote() = default;

    fachnote(const fachnote&) = delete;
    fachnote& operator=(const fachnote&) = delete;
    fachnote(fachnote&&) = default;
    fachnote& operator=(fachnote&&) = default;
};

#endif
