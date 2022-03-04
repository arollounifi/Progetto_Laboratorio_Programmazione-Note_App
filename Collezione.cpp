//
//Definizioni dei metodi della classe "Collezione"
//Created by Rollo Aurelio
//

#include "Collezione.h"
#include "Notes.h"

//CTor & DTor
Collezione::Collezione() : Titolo("Titolo Stock"), TotalLockedNotes(0), TotalNotes(0) {}
Collezione::Collezione(std::string Tit)  : Titolo(Tit), TotalLockedNotes(0), TotalNotes(0) {}

Collezione::~Collezione() {
    std::cout << "\nLa collezione " << this->Titolo << " e' stata eliminata";
}

//getter & setter
const std::string &Collezione::getTitolo() const {
    return Titolo;
}

const std::vector<Notes> &Collezione::getCollection() const {
    return Collection;
}
void Collezione::setCollection(const std::vector<Notes> &collection) {
    Collection = collection;
}

int Collezione::getTotalNotes() const {
    return TotalNotes;
}
void Collezione::setTotalNotes(int totalNotes) {
    TotalNotes = totalNotes;
}

int Collezione::getTotalLockedNotes() const {
    return TotalLockedNotes;
}
void Collezione::setTotalLockedNotes(int totalLockedNotes) {
    TotalLockedNotes = totalLockedNotes;
}

//metodi inerenti alla classe
int Collezione::CollectionSize() const {
    return Collection.size();
}

Notes * Collezione::getNote(int i){
    return &(Collection[i]);
}















