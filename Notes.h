//
// Classe che rappresenta una nota che puo' eventualmente essere bloccata.
// Created by Rollo Aurelio.
//

#ifndef UNTITLED_NOTES_H
#define UNTITLED_NOTES_H

#include <list>
#include <string>

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
    Notes(const std::string &Titolo,const std::string &Testo, bool Lock);

    //metodi inerenti alla classe
    std::string PrintLock () const;

};

#endif //UNTITLED_NOTES_H
