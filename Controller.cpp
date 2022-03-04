//
// Definizioni dei metodi della classe "Controller".
// Created by Rollo Aurelio.
//

#include "Controller.h"

//getters & setter
int Controller::getNotesCount() const {
    return NotesCount;
}

int Controller::getLockNotesCount() const {
    return LockNotesCount;
}

void Controller::setCol(Collezione *col) {
    Col = col;
}

//metodi inerenti alla classe
void Controller::ViewCol() const {
    std::cout << Col->getTitolo() << std::endl;
    std::cout << "      Note: " << std::endl;
    for(int i = 0; i<Col->CollectionSize(); i++){
        Notes* note = Col->getNote(i);
        std::cout << "         " << i << ") Title: " << note->getTitle() << note->PrintLock() << std::endl;
    }
    std::cout << "In questa collezione ci sono " << NotesCount << " di cui " << LockNotesCount << " bloccate." << std::endl;
}

void Controller::AddNote(Notes &NewNote) {
    std::vector<Notes> vec = Col->getCollection();
    vec.push_back(NewNote);
    Col->setCollection(vec);
    Col->setTotalNotes(Col->getTotalNotes()+1);
    NotesCount ++;
    if(NewNote.isLocked()) {
        LockNotesCount++;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()+1);
    }
    notify();
}

void Controller::RemoveNote(int i) {
    std::vector<Notes> vec = Col->getCollection();
    NotesCount --;
    Col->setTotalNotes(Col->getTotalNotes()-1);
    if(vec[i].isLocked()){
        LockNotesCount --;
        Col->setTotalLockedNotes(Col->getTotalLockedNotes()-1);
    }
    vec.erase(vec.begin()+i);
    Col->setCollection(vec);
    notify();
}

void Controller::ViewNote(int i) const {
    Notes *nota = Col->getNote(i);
    std::cout << "Titolo: " << nota->getTitle() << "\nText: " << nota->getText() << std::endl;
}

bool Controller::IsNoteLocked(int i) const {
    Notes *nota = Col->getNote(i);
    return nota->isLocked();
}

void Controller::ModifyNote(int i, int choice, std::string &t) {
    Notes *nota = Col->getNote(i);
    if(choice == 1) {
        nota->setTitle(t);
    }
    else if(choice == 2){
        nota->setText(t);
    }
    else{
        nota->setLocked(!nota->isLocked());
    }
}


//metodi Subject
void Controller::notify() {
    for(auto & observer : observers){
        observer->update();
    }
}

void Controller::addObserver(Observer *o) {
    observers.push_back(o);
}

void Controller::removeObserver(Observer *o) {
    observers.remove(o);
}





