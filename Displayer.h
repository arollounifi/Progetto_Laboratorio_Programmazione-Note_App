//
// Created by aurel on 06/01/2022.
//

#ifndef UNTITLED_DISPLAYER_H
#define UNTITLED_DISPLAYER_H

#include "Observer.h"
#include "Subject.h"
#include "Collezione.h"

class Displayer : public Observer{
private:
    int LockNotes;
    int TotalNotes;
    Collezione* Collection;

public:
    //CTor & DTor
    explicit Displayer( Collezione* collection) : Collection(collection), LockNotes(0), TotalNotes(0){
        Collection->addObserver(this);
    }
    ~Displayer() override;

    //getter & setter
    int getImpNotes() const;
    Subject *getCollection() const;
    void setCollection(Collezione *collection);

    //methods
    void update() override;
    void show() const;
};

#endif //UNTITLED_DISPLAYER_H
