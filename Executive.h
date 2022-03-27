//
// Classe con lo scopo di permettere l'interazione con le note e le collezioni.
// Presenta 2 contatori per tenere traccia di quante note (totali e bloccate) siano presenti in tutte le collezioni.
// Created by Rollo Aurelio.
//

#ifndef PROGETTOLAB_EXECUTIVE_H
#define PROGETTOLAB_EXECUTIVE_H

#include "Collezione.h"
#include "Notes.h"
#include "Subject.h"
#include <iostream>

class Executive : public Subject{
private:
    Collezione* Col;
    int TotNotesCount, TotLockNotesCount, ColNotesCount, ColLockNotesCount;
    std::list<Observer*> observers;

public:
    //costruttore
    explicit Executive(Collezione* c): Col(c), TotNotesCount(0), TotLockNotesCount(0), ColLockNotesCount(0), ColNotesCount(0){}

    //getters & setters
    int getTotNotesCount() const;
    int getTotLockNotesCount() const;
    int getColNotesCount() const;
    int getColLockNotesCount() const;

    void setCol(Collezione *col);
    Collezione *getCol() const;

    void setTotNotesCount(int totNotesCount);
    void setTotLockNotesCount(int totLockNotesCount);
    void setColNotesCount(int colNotesCount);
    void setColLockNotesCount(int colLockNotesCount);

    //metodi inerenti alla classe
    void ViewCol () const;
    void AddNote(const Notes &NewNote);
    void RemoveNote(int i);
    void ViewNote(int i) const;
    bool IsNoteLocked(int i) const;
    void ModifyNote(int i, int choice,const std::string& t);

    //metodi subject
    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
};


#endif //PROGETTOLAB_EXECUTIVE_H
