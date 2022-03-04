//
// Definizioni dei metodi della classe "Notes".
// Created by Rollo Aurelio.
//

#include "Notes.h"

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

//metodi inerenti alla clase
std::string Notes::PrintLock() const {
    if(isLocked()){
        return "  -  (Lock)";
    }
    else{
        return " ";
    }
}


