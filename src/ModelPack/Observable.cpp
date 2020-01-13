//
// Created by daniel on 13/01/2020.
//

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
    for (int i = 0; i < listObservable.size(); ++i) {
        listObservable.at(i).update();
    }
}