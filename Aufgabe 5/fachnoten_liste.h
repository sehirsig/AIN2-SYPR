/*
 * fachnoten_liste.h
 *
 * eingebettete Klasse.
 *
 * Autor: S.Hirsig
 * Erstellt am: 01.01.2021
 */
#ifndef FACHNOTEN_LISTE_H
#define FACHNOTEN_LISTE_H

#include "fachnote.h"

class fachnoten_liste final
{
    // Entity-Klasse ohne Kopier- und Move-Semantik
    fachnoten_liste(fachnoten_liste&) = delete;
    fachnoten_liste& operator=(fachnoten_liste&) = delete;
    fachnoten_liste(fachnoten_liste&&) = delete;
    fachnoten_liste& operator=(fachnoten_liste&&) = delete;

private:
    class element;
    element *head;
    void (*adresse)(fachnote*);

public:

    explicit fachnoten_liste(void (*func)(fachnote*));
    ~fachnoten_liste();
    fachnoten_liste& insert(fachnote*);

    class iterator final
    {
    private:
        element *current;
        explicit iterator(element*);
    public:
        bool operator!=(const iterator&) const;
        fachnote*& operator*() const;
        iterator& operator++();

        friend class fachnoten_liste;
    };

    iterator begin();
    iterator end();
};

#endif

