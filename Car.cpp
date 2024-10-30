//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//
#include "Car.h"
#include "Vehicle.h"
#include <iostream>
#include<iostream>
#include<string>
using namespace std;

Car::Car(string _make, string _model, int _year, Engine _engine, int _doors)
        : Vehicle("Car", _make, _model, _year, _engine), doors(_doors) {}

void Car::display()  {
    Vehicle::display();
    cout << "Number of Doors: " << doors << endl;
}

json Car::toJson()  {
    return {
            {"type", "Car"},
            {"details", Vehicle::toJson()},
            {"doors", doors}
    };
}
