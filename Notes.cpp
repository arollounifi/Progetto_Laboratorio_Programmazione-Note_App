//
// Created by aurelio on 13/08/21.
//

#include "Notes.h"
#include <iostream>

//Ctor & Dtor
Notes::Notes() : Title("Titolo stock"), Text("Test stock"), Locked(false) {}
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

void Notes::Modify(int& scelta, std::string& testo) {
    if(scelta == 1) {
        Title = testo;
    }
    else if(scelta == 2){
        Text = testo;
    }
    else{
        Locked = !Locked;
    }
}

void Notes::ShowNote() const {
    std::cout << "Titolo: " << Title << "\nText: " << Text << std::endl;
}

std::string Notes::PrintLock() const {
    if(isLocked()){
        return "  -  (Lock)";
    }
    else{
        return " ";
    }
}


