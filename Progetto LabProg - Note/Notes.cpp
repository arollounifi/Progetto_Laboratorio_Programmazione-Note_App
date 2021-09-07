//
// Created by aurelio on 13/08/21.
//

#include "Notes.h"
#include "Collezione.h"
#include <iostream>

//Ctor & Dtor
Notes::Notes() {
    char Lok;
    std::cout << "==== Creazione di una  nuova nota ===="<< std::endl;
    std::cout << "\nInserire il titolo della nota."<< std::endl;
    std::cin.ignore();
    std::getline(std::cin, Title);
    std::cout << "\nInserire il testo della nota." << std::endl;
    std::getline(std::cin, Text);
    std::cout << "\nDo you want to lock this note? (0=y or 1=n)" << std::endl;
    std::cin >> Lok;
    if (Lok == 0) {
        this->Locked = true;
    }
    else if (Lok == 1) {
        this->Locked = false;
    }

}
Notes::~Notes() {
    std::cout << "\nLa nota " << this->Title << " e' stata eliminata";
}


//getter and setter
const std::string &Notes::getTitle() const {
    return Title;
}
void Notes::setTitle(const std::string &title) {
    Title = title;
}

const std::string &Notes::getText() const {
    return Text;
}
void Notes::setText(const std::string &text) {
    Text = text;
}

bool Notes::isLocked() const {
    return Locked;
}
void Notes::setLocked(bool locked) {
    Locked = locked;
}
