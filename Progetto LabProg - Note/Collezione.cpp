//
// Created by aurelio on 16/08/21.
//

#include "Collezione.h"
#include "Notes.h"

//getter & setter
const std::string &Collezione::getTitolo() const {
    return Titolo;
}
void Collezione::setTitolo(const std::string &titolo) {
    Titolo = titolo;
}

const std::vector<Notes> &Collezione::getCollection() const {
    return Collection;
}
void Collezione::setCollection(const std::vector<Notes> &collection) {
    Collection = collection;
}

//costruttori
Collezione::Collezione() {
    std::cout << "\n==== Creazione di una  nuova Collezione ====";
    std::cout << "\n \nInserire il titolo della Collezione:";
    std::cin.ignore();
    std::getline(std::cin, Titolo);
}
Collezione::Collezione(std::string Tit) {
    Titolo = Tit;
}

//distruttore
Collezione::~Collezione() {
    std::cout << "\nLa collezione " << this->Titolo << " e' stata eliminata";
}

void Collezione::View() {
    std::cout << "\n\nNote: " << std::endl;
    for(int i = 0; i<Collection.size(); i++){
    }
} //vengono stampati i titoli  delle note contenute nella collezione

void Collezione::AddNotes(Notes &NewNote) {
    Collection.push_back(NewNote);
}

void Collezione::RemoveNote(int i) {
    Collection.erase(Collection.begin()+i);
}




