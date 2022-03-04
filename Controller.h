//
// Classe con lo scopo di permettere l'interazione con le note e le collezioni.
// Presenta 2 contatori per tenere traccia di quante note (totali e bloccate) siano presenti in tutte le collezioni.
// Created by Rollo Aurelio.
//

#ifndef PROGETTOLAB_CONTROLLER_H
#define PROGETTOLAB_CONTROLLER_H

#include "Collezione.h"
#include "Notes.h"
#include "Subject.h"
#include <iostream>

class Controller : public Subject{
private:
    Collezione* Col;
    int NotesCount, LockNotesCount;
    std::list<Observer*> observers;

public:
    //costruttore
    explicit Controller(Collezione* c): Col(c), NotesCount(0), LockNotesCount(0){}

    //getters & setters
    int getNotesCount() const;
    int getLockNotesCount() const;

    void setCol(Collezione *col);

    //metodi inerenti alla classe
    void ViewCol () const;
    void AddNote(Notes &NewNote);
    void RemoveNote(int i);
    void ViewNote(int i) const;
    bool IsNoteLocked(int i) const;
    void ModifyNote(int i, int choice, std::string& t);

    //metodi subject
    void notify() override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
};


#endif //PROGETTOLAB_CONTROLLER_H
