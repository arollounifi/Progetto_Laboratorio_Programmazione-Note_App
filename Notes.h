//
// Created by aurelio on 13/08/21.
//

#ifndef UNTITLED_NOTES_H
#define UNTITLED_NOTES_H

#include <list>
#include <string>
#include "Subject.h"
#include "Observer.h"

class Collezione;

class Notes{
private:
    std::string Title;
    std::string Text;
    bool Locked;


public:
    //getter & setter
    const std::string &getTitle() const;
    void setTitle(const std::string &title);

    const std::string &getText() const;
    void setText(const std::string &text);
    
    bool isLocked() const;
    void setLocked(bool locked);

    //Ctor & Dtor
    Notes();
    Notes(std::string Titolo, std::string Testo, bool Lock);
    ~Notes();

    //metodi inerenti alla classe
    void Modify ();


};

#endif //UNTITLED_NOTES_H
