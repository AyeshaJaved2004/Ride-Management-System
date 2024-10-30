//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//
#include "Rickshaw.h"
#include <iostream>
#include<iostream>
#include<string>
using namespace std;

Rickshaw::Rickshaw(string _make, string _model, int _year, Engine _engine, string _driverName)
        : Vehicle("Rickshaw", _make, _model, _year, _engine), driverName(_driverName) {}


void Rickshaw::display()   {
    Vehicle::display();
    cout << "Driver Name: " << driverName << endl;
}

json Rickshaw::toJson()  {
    return {
            {"type", "Rickshaw"},
            {"details", Vehicle::toJson()},
            {"driverName", driverName}
    };
}

ostream& operator<<(ostream& os, const Rickshaw& rickshaw) {
    os << "Type: Rickshaw" << endl;
    os << "Driver Name: " << rickshaw.driverName << endl;
    return os;
}