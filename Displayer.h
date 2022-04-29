//
// Observer Concreto che monitora lo stato dei contatori della classe Executive.
// Created by Rollo Aurelio.
//

#ifndef UNTITLED_DISPLAYER_H
#define UNTITLED_DISPLAYER_H

#include "Observer.h"
#include "Subject.h"
#include "Executive.h"

class Displayer : public Observer{
private:
    int TotalLockNotes, TotalNotes, CollectionNotes, CollectionLockNotes;
    Executive* pExecutive;

public:
    //CTor & DTor
    explicit Displayer(Executive* c) : pExecutive(c), TotalLockNotes(0), TotalNotes(0), CollectionLockNotes(0), CollectionNotes(0){
        pExecutive->addObserver(this);
    }
    ~Displayer() override;

    //getter
    int getTotalLockNotes() const;
    int getTotalNotes() const;
    int getCollectionNotes() const;
    int getCollectionLockNotes() const;
    Subject *getpExecutive() const;

    //metodi inerenti alla classe
    void update() override;
    void ShowTotal() const;
    void ShowCol() const;
};

#endif //UNTITLED_DISPLAYER_H
