//
// Classe che ha lo scopo di raccogliere le note create.
// Presenta 2 contatori per tenere traccia di quante note (totali e bloccate) sono presenti in essa.
// Created by Rollo Aurelio
//

#ifndef UNTITLED_COLLEZIONE_H
#define UNTITLED_COLLEZIONE_H

#include <iostream>
#include <vector>
#include "Notes.h"

class Collezione{
private:
    std::string Titolo;
    std::vector<Notes> Collection;
    int TotalNotes;
    int TotalLockedNotes;


public:
    //Ctor & Dtor
    Collezione();
    explicit Collezione(const std::string &Tit);
    ~Collezione();

    //getter & setter
    const std::string &getTitolo() const;

    const std::vector<Notes> &getCollection() const;
    void setCollection(const std::vector<Notes> &collection);

    int getTotalNotes() const;
    void setTotalNotes(int totalNotes);

    int getTotalLockedNotes() const;
    void setTotalLockedNotes(int totalLockedNotes);

    //metodi inerenti alla classe
    int CollectionSize() const;
    Notes * getNote(int i);


};

#endif //UNTITLED_COLLEZIONE_H
