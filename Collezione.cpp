//
// Created by aurelio on 16/08/21.
//

#include "Collezione.h"
#include "Notes.h"
#include "Displayer.h"


//getter & setter
const std::string &Collezione::getTitolo() const {
    return Titolo;
}
void Collezione::setTitolo(const std::string &titolo) {
    Titolo = titolo;
}
int Collezione::getTotalNotes() const {
    return TotalNotes;
}
int Collezione::getTotalLockedNotes() const {
    return TotalLockedNotes;
}

Observer *Collezione::getObs() const {
    return obs;
}


//costruttori
Collezione::Collezione() : Titolo("Titolo Stock"), TotalLockedNotes(0), TotalNotes(0) {}
Collezione::Collezione(std::string Tit)  : Titolo(Tit), TotalLockedNotes(0), TotalNotes(0) {}

//distruttore
Collezione::~Collezione() {
    std::cout << "\nLa collezione " << this->Titolo << " e' stata eliminata";
}

//metodi della classe
void Collezione::View() {
    std::cout << Titolo << std::endl;
    std::cout << "      Note: " << std::endl;
    for(int i = 0; i<Collection.size(); i++){
        std::cout << "         " << i << ") Title: " << Collection[i].getTitle() << Collection[i].PrintLock() << std::endl;
    }
} //vengono stampati i titoli  delle note contenute nella collezione

void Collezione::AddNotes(Notes &NewNote) {
    Collection.push_back(NewNote);
    TotalNotes ++;
    if (NewNote.isLocked())
        TotalLockedNotes ++;
    notify();

}

void Collezione::RemoveNote(int i) {
    TotalNotes --;
    if(Collection[i].isLocked())
        TotalLockedNotes --;
    Collection.erase(Collection.begin()+i);
    notify();
}

void Collezione::ViewNote(int i) {
    Collection[i].ShowNote();
} //viengono stampati tiolo e testo di una certa nota

void Collezione::ModifyNote(int i, int scelta, std::string& TestoTemp) {
    Collection[i].Modify(scelta, TestoTemp);
}

int Collezione::CollectionSize() {
    return Collection.size();
}

bool Collezione::IsNoteLocked(int i) {
    return Collection[i].isLocked();
}

//metodi Subject
void Collezione::notify() {
    for(auto & observer : observers) {
        observer->update();
    }
}

void Collezione::addObserver(Observer *o) {
    observers.push_back(o);
}

void Collezione::removeObserver(Observer *o) {
    observers.remove(o);
}






