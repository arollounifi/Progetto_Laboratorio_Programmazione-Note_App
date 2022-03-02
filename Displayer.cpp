//
// Created by aurel on 06/01/2022.
//

#include <iostream>
#include "Displayer.h"

Displayer::~Displayer() {
    Collection->removeObserver(this);
}

void Displayer::update() {
    LockNotes = Collection->getTotalLockedNotes();
    TotalNotes = Collection->getTotalNotes();
}

void Displayer::show() const {
    std::cout << "Questa collezione ha un totale di " << TotalNotes << " di cui " << LockNotes << " bloccate." << std::endl;
}

int Displayer::getImpNotes() const {
    return LockNotes;
}

Subject *Displayer::getCollection() const {
    return Collection;
}

void Displayer::setCollection(Collezione *collection) {
    Collection = collection;
}


