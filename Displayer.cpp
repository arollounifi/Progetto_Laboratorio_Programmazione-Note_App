//
// Definizioni dei metodi della classe "Displayer".
// Created by Rollo Aurelio.
//

#include <iostream>
#include "Displayer.h"

//distruttore
Displayer::~Displayer() {
    controller->removeObserver(this);
}

//getter
int Displayer::getImpNotes() const {
    return LockNotes;
}

Subject *Displayer::getCollection() const {
    return controller;
}

//metodi inerenti alla classe
void Displayer::update() {
    LockNotes = controller->getLockNotesCount();
    TotalNotes = controller->getNotesCount();
}

void Displayer::show() const {
    std::cout << "In totale ci sono " << TotalNotes << " di cui " << LockNotes << " bloccate." << std::endl;
}




