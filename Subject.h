//
// Interfaccia Subject.
// Created Rollo Aurelio.
//

#ifndef UNTITLED_SUBJECT_H
#define UNTITLED_SUBJECT_H
#include "Observer.h"

class Subject{
public:
    virtual ~Subject() = default;
    virtual void notify() = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;

};
#endif //UNTITLED_SUBJECT_H
