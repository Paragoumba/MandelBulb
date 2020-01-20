#include "Observable.h"

Observable::Observable() = default;

Observable::~Observable() = default;

void Observable::addObserver(Observer& observer) {

    listObservable.push_back(observer);

}

void Observable::deleteObserver(Observer _observer) {
//    std::vector<Observer>::iterator i = listObservable.begin();
//    for (int j = 0; j < listObservable.size(); ++j) {
//        if(listObservable.at(j) == _observer){
//            listObservable.erase(i);
//            return;
//        }
//        else{
//            std::advance(i, 1);
//        }
//    }
}

void Observable::notifyObservers() {

   int size = (int)(listObservable.size());
    for (unsigned int i = 0; i < size; ++i) {

        listObservable.at(i).update();

    }

}