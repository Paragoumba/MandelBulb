#include "Observable.h"

Observable::Observable(){

}

Observable::~Observable(){

}

void Observable::addObserver(Observer _observer) {

    listObservable.push_back(_observer);

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

    int size = listObservable.size();
    for (int i = 0; i < size; ++i) {

        listObservable.at(i).update();

    }
}