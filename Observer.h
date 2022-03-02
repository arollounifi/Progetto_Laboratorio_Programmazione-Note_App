//
// Created by aurel on 06/01/2022.
//

#ifndef UNTITLED_OBSERVER_H
#define UNTITLED_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};
#endif //UNTITLED_OBSERVER_H
