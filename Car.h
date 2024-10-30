//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//

#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H
#include "Vehicle.h"
#include "nlohmann/json.hpp"
#include<iostream>
#include<string>
using namespace std;
class Car : public Vehicle {
private:
    int doors;

public:
    // Constructor
    Car(string _make, string _model, int _year, Engine _engine, int _doors);

    // Getter for doors
    int getDoors() const {
        return doors;
    }

    // Setter for doors
    void setDoors(int _doors) {
        doors = _doors;
    }

    // Display function
    void display() override;

    // To JSON function
    json toJson()  override;
};
#endif //UNTITLED_CAR_H
