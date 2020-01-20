#include "Controller.h"

Controller::Controller(Data& data) {

    this->data = data;

}

Controller::~Controller() = default;

Data Controller::getData() {

    return data;

}