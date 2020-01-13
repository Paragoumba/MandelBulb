//
// Created by daniel on 10/01/2020.
//

#include "Controller.h"

Controller::Controller(Data data){
    this->data=data;
}

Controller::~Controller() {}


Data Controller::getData(){
    return this->data;
}