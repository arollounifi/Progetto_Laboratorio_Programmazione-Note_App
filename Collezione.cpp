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
    std::cout << "Numero di note: " << TotalNotes << ", di cui bloccate: " << TotalLockedNotes << std::endl;
    std::cout << "      Note: " << std::endl;
    for(int i = 0; i<Collection.size(); i++){
        std::cout << "         " << i << ") Title: " << Collection[i].getTitle() << std::endl;
    }
} //vengono stampati i titoli  delle note contenute nella collezione

void Collezione::AddNotes(Notes &NewNote) {
    Collection.push_back(NewNote);
    TotalNotes ++;
    if (NewNote.isLocked())
        TotalLockedNotes ++;
    notify("added");

}

void Collezione::RemoveNote(int i) {
    TotalNotes --;
    if(Collection[i].isLocked())
        TotalLockedNotes --;
    Collection.erase(Collection.begin()+i);
    notify("deleted");
}

void Collezione::ViewNote(int i) {
    Collection[i].ShowNote();
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
            TotalLockedNotes --;
        }
    }
    else
        Collection[i].Modify();
}//viene modificata una certa nota se essa non è bloccata

void Collezione::notify(std::string action) {
    for(auto & observer : observers) {
        observer->update(action);
    }
}

void Collezione::addObserver(Observer *o) {
    observers.push_back(o);
}

void Collezione::removeObserver(Observer *o) {
    observers.remove(o);
}

int Collezione::CollectionSize() {
    return Collection.size();
}




