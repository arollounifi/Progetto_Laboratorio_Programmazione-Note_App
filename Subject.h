//
// Created by aurel on 06/01/2022.
//

#ifndef UNTITLED_SUBJECT_H
#define UNTITLED_SUBJECT_H
#include "Observer.h"

class Subject{
public:
    virtual ~Subject() = default;
    virtual void notify(std::string action) = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;

};
#endif //UNTITLED_SUBJECT_H
