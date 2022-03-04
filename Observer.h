//
// Interfaccia Observer.
// Created by Rollo Aurelio.
//

#ifndef UNTITLED_OBSERVER_H
#define UNTITLED_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};
#endif //UNTITLED_OBSERVER_H
