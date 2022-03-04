//
// Observer Concreto che monitora lo stato dei contatori della classe Controller.
// Created by Rollo Aurelio.
//

#ifndef UNTITLED_DISPLAYER_H
#define UNTITLED_DISPLAYER_H

#include "Observer.h"
#include "Subject.h"
#include "Controller.h"

class Displayer : public Observer{
private:
    int LockNotes;
    int TotalNotes;
    Controller* controller;

public:
    //CTor & DTor
    explicit Displayer( Controller* c) : controller(c), LockNotes(0), TotalNotes(0){
        controller->addObserver(this);
    }
    ~Displayer() override;

    //getter & setter
    int getImpNotes() const;
    Subject *getCollection() const;

    //metodi inerenti alla classe
    void update() override;
    void show() const;
};

#endif //UNTITLED_DISPLAYER_H
