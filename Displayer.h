//
// Created by aurel on 06/01/2022.
//

#ifndef UNTITLED_DISPLAYER_H
#define UNTITLED_DISPLAYER_H

#include "Observer.h"
#include "Subject.h"

class Displayer : public Observer{
private:
    int ImpNotes;
    Subject* Collection;

public:
    //CTor & DTor
    explicit Displayer( Subject* collection) : Collection(collection), ImpNotes(0){
        Collection->addObserver(this);
    }
    ~Displayer() override;

    //getter & setter
    int getImpNotes() const;
    Subject *getCollection() const;

    //methods
    void update(std::string action) override;
    void show() const;
};

#endif //UNTITLED_DISPLAYER_H
