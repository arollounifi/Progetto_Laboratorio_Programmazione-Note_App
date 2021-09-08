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

void Collezione::ViewNote(int i) {
    std::cout << "Title: " << Collection[i].getTitle() << "\nText: " << Collection[i].getText() << std::endl;
} //viengono stampati tiolo e testo di una certa nota

void Collezione::ModifyNote(int i) {
    int choice;
    std::cout << Collection[i].isLocked() << std::endl;
    if(Collection[i].isLocked()){
        std::cout << "This note is locked! Do you want to unlock it?(1=yes or 0=no)" << std::endl;
        do{
            std::cin >> choice;
        }while (choice != 1 && choice != 0);
        if (choice == 1){
            Collection[i].setLocked(false);
        }
    }
    else
        Collection[i].Modify();
}//viene modificata una certa nota se essa non è bloccata

Notes Collezione::ExtractNote(int i) {
    return Collection[i];
}




