//
// Definizioni dei metodi della classe "Executive".
// Created by Rollo Aurelio.
//

#include "Executive.h"

//getters & setter
int Executive::getTotNotesCount() const {
    return TotNotesCount;
}

int Executive::getTotLockNotesCount() const {
    return TotLockNotesCount;
}

void Executive::setCol(Collezione *col) {
    Col = col;
    ColNotesCount=Col->getTotalNotes();
    ColLockNotesCount=Col->getTotalLockedNotes();
    notify();
}

int Executive::getColNotesCount() const {
    return ColNotesCount;
}

int Executive::getColLockNotesCount() const {
    return ColLockNotesCount;
}

Collezione *Executive::getCol() const {
    return Col;
}

//metodi inerenti alla classe
void Executive::ViewCol() const {
    std::cout << Col->getTitolo() << std::endl;
    std::cout << "      Note: " << std::endl;
    for(int i = 0; i<Col->CollectionSize(); i++){
        Notes* note = Col->getNote(i);
        std::cout << "         " << i << ") Title: " << note->getTitle() << note->PrintLock() << std::endl;
    }
}

void Executive::AddNote(const Notes &NewNote) {
    std::vector<Notes> vec = Col->getCollection();
    vec.push_back(NewNote);
    Col->setCollection(vec);
    TotNotesCount ++;
    Col->setTotalNotes(Col->getTotalNotes()+1);
    ColNotesCount=Col->getTotalNotes();
    if(NewNote.isLocked()) {
        TotLockNotesCount++;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()+1);
        ColLockNotesCount=Col->getTotalLockedNotes();
    }
    notify();
}

void Executive::RemoveNote(int i) {
    std::vector<Notes> vec = Col->getCollection();
    TotNotesCount --;
    Col->setTotalNotes(Col->getTotalNotes()-1);
    ColNotesCount=Col->getTotalNotes();
    if(vec[i].isLocked()){
        TotLockNotesCount --;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()-1);
        ColLockNotesCount=Col->getTotalLockedNotes();
    }
    vec.erase(vec.begin()+i);
    Col->setCollection(vec);
    notify();
}

void Executive::ViewNote(int i) const {
    Notes *nota = Col->getNote(i);
    std::cout << "Titolo: " << nota->getTitle() << "\nText: " << nota->getText() << std::endl;
}

bool Executive::IsNoteLocked(int i) const {
    Notes *nota = Col->getNote(i);
    return nota->isLocked();
}

bool Executive::ModifyNote(int i, int choice, const std::string& t) {
    Notes nota(" ", " ", false);
    nota.setTitle(Col->getNote(i)->getTitle());
    nota.setText(Col->getNote(i)->getText());
    if (IsNoteLocked(i)){
        return false;
    }
    else {
        if(choice == 1) {
            nota.setTitle(t);
        }
        else if(choice == 2){
            nota.setText(t);
        }
        else{
            nota.setLocked(!nota.isLocked());
            TotLockNotesCount++;
            Col->setTotalLockedNotes(Col->getTotalLockedNotes()+1);
            ColLockNotesCount=Col->getTotalLockedNotes();
            notify();
        }
        std::vector<Notes> Vec = Col->getCollection();
        auto itPos = Vec.begin()+i;
        Vec.insert(itPos, nota);
        Col->setCollection(Vec);
        return true;
    }


}

//metodi Subject
void Executive::notify() {
    for(auto & observer : observers){
        observer->update();
    }
}

void Executive::addObserver(Observer *o) {
    observers.push_back(o);
}

void Executive::removeObserver(Observer *o) {
    observers.remove(o);
}













