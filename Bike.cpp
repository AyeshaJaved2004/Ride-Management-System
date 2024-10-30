#include "Bike.h"
#include<string>
#include <iostream>
using namespace std;


Bike::Bike(string _make, string _model, int _year, Engine _engine, string _bikeType)
        : Vehicle("Bike", _make, _model, _year, _engine), bikeType(_bikeType) {}


void Bike::display() {
    Vehicle::display();
    cout << "Bike Type: " << bikeType << endl;
}

json Bike::toJson()  {
    return {
            {"type", "Bike"},
            {"details", Vehicle::toJson()},
            {"bikeType", bikeType}
    };
}
