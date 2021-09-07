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

class Collezione{
private:
    std::string Titolo;
    std::vector<Notes> Collection;

public:
    //Ctor & Dtor
    Collezione();
    explicit Collezione(std::string Tit);
    ~Collezione();

    //getter & setter
    const std::string &getTitolo() const;
    void setTitolo(const std::string &titolo);

    const std::vector<Notes> &getCollection() const;
    void setCollection(const std::vector<Notes> &collection);

    //metodi inerenti alla classe
    void View();
    void AddNotes (Notes& NewNote);
    void RemoveNote (int i);

};

#endif //UNTITLED_COLLEZIONE_H
