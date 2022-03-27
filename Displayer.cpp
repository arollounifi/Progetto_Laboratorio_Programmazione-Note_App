//
// Definizioni dei metodi della classe "Displayer".
// Created by Rollo Aurelio.
//

#include <iostream>
#include "Displayer.h"

//distruttore
Displayer::~Displayer() {
    pExecutive->removeObserver(this);
}

//getter
int Displayer::getTotalLockNotes() const {
    return TotalLockNotes;
}
int Displayer::getTotalNotes() const {
    return TotalNotes;
}
int Displayer::getCollectionNotes() const {
    return CollectionNotes;
}
int Displayer::getCollectionLockNotes() const {
    return CollectionLockNotes;
}
Subject *Displayer::getpExecutive() const {
    return pExecutive;
}

//metodi inerenti alla classe
void Displayer::update() {
    TotalLockNotes = pExecutive->getTotLockNotesCount();
    TotalNotes = pExecutive->getTotNotesCount();
    CollectionLockNotes = pExecutive->getColLockNotesCount();
    CollectionNotes = pExecutive->getColNotesCount();
}

void Displayer::ShowTotal() const {
    std::cout << "In totale ci sono " << TotalNotes << " di cui " << TotalLockNotes << " bloccate." << std::endl;
}

void Displayer::ShowCol() const {
    std::cout << "In questa collezione ci sono " << CollectionNotes << " di cui " << CollectionLockNotes << " bloccate." << std::endl;
}








