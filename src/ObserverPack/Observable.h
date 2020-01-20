#ifndef MANDELBULB_OBSERVABLE_H
#define MANDELBULB_OBSERVABLE_H

#include <vector>

#include "Observer.h"

class Observable {
private:
    std::vector<Observer> listObservable;

public:
    Observable();
    ~Observable();
    void addObserver(Observer& observer);
    static void deleteObserver(Observer _observer);
    void notifyObservers();

};

#endif //MANDELBULB_OBSERVABLE_H
