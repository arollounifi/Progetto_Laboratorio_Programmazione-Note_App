//
// Created by aurelio on 13/08/21.
//

#include "Notes.h"
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
        this->Locked = false;

    }
    else if (Lok == 1) {
        this->Locked = true;

    }

}
Notes::~Notes() {
    std::cout << "\nLa nota " << this->Title << " e' stata eliminata";
}
Notes::Notes(std::string Titolo, std::string Testo, bool Lock) : Title(Titolo), Text(Testo), Locked(Lock) {
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

void Notes::Modify() {
    int selezione;
    std::cout << "Cosa si vuole modificare?\n" << std::endl;
    std::cout << "1 - Titolo\n" << std::endl;
    std::cout << "2 - Testo\n" << std::endl;
    std::cout << "3 - Sicurezza\n" << std::endl;
    do{
        std::cin >> selezione;
    }while (selezione!= 1 && selezione != 2 && selezione != 3);
    switch (selezione) {
        case 1:
            std::cout << "\n Inserire il titolo della nota." << std::endl;
            std::cin.ignore();
            std::getline(std::cin, Title);
            break;
        case 2:
            std::cout << "\n Inserire il testo della nota." << std::endl;
            std::cin.ignore();
            std::getline(std::cin, Text);
            break;
        case 3:
            if (this->Locked){
                this->Locked = false;
                std::cout<<"la nota non è più privata." << std::endl;
            }
            else{
                this->Locked=true;
                std::cout<<"la nota è privata." << std::endl;

            }
            break;
        default:{
            std::cout << "I seriously have no idea how you managed to execute this line of code" << std::endl;
            break;
        }
    }
}


