//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//
#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const char *_type,  string _make,  string _model, int _year,  Engine _engine)
        : type(_type), make(_make), model(_model), year(_year), engine(&_engine), isStarted(false),
          safetyFeatures(safetyFeatures) {}

Vehicle::~Vehicle() {}

void Vehicle::start() {
    isStarted = true;
}

void Vehicle::stop() {
    isStarted = false;
}

bool Vehicle::isVehicleStarted()  {
    return isStarted;
}

void Vehicle::display()  {
    cout << "Type: " << type << ", Make: " << make << ", Model: " << model << ", Year: " << year << endl;
//    std::cout << "Engine Type: " << engine->toJson() << std::endl;
    if (isStarted) {
        cout << "Vehicle is started" << endl;
    } else {
        cout << "Vehicle is not started" << endl;
    }
}

json Vehicle::toJson()  {
    return {
            {"type", type},
            {"make", make},
            {"model", model},
            {"year", year},
//            {"engine", engine->toJson()},
            {"isStarted", isStarted}
    };
}

