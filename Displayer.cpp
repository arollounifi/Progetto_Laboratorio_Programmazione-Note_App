//
// Created by aurel on 06/01/2022.
//

#include <iostream>
#include "Displayer.h"

Displayer::~Displayer() {
    Collection->removeObserver(this);
}

void Displayer::update(std::string action) {
    if (action == "added"){
        ImpNotes++;
        std::cout << "\nUna nota è stata contrassegnata come importante!" << std::endl;
    }
    else if (action == "deleted"){
        ImpNotes--;
        std::cout << "\nUna nota è stata tolta dalle note importanti!" << std::endl;
    }
}

void Displayer::show() const {
    std::cout << "Numero di note Private: " << ImpNotes << std::endl;
}

int Displayer::getImpNotes() const {
    return ImpNotes;
}

Subject *Displayer::getCollection() const {
    return Collection;
}


