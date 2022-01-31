//
// Created by aurelio on 16/08/21.
//

#ifndef UNTITLED_COLLEZIONE_H
#define UNTITLED_COLLEZIONE_H

#include <iostream>
#include <vector>
#include <list>
#include "Subject.h"
#include "Observer.h"

class Notes;

class Collezione : public Subject{
private:
    std::string Titolo;
    std::vector<Notes> Collection;
    std::list<Observer*> observers;


public:
    //Ctor & Dtor
    Collezione();
    explicit Collezione(std::string Tit);
    ~Collezione() override;

    //getter & setter
    const std::string &getTitolo() const;
    void setTitolo(const std::string &titolo);

    const std::vector<Notes> &getCollection() const;
    void setCollection(const std::vector<Notes> &collection);

    //metodi inerenti alla classe
    void View();
    void AddNotes (Notes& NewNote);
    void RemoveNote (int i);
    void ViewNote(int i);
    void ModifyNote(int i);

    //Subject
    void notify(std::string action) override;
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
};

#endif //UNTITLED_COLLEZIONE_H
