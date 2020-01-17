#include "Controller.h"

Controller::Controller(Data data) {

    this->data=data;

}

Controller::~Controller() {}

Data Controller::getData() {

    return this->data;

}