//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//

#ifndef UNTITLED_RICKSHAW_H
#define UNTITLED_RICKSHAW_H
#include "Vehicle.h"
#include "nlohmann/json.hpp"
#include<iostream>
#include<string>
using namespace std;

class Rickshaw : public Vehicle {
private:
    string driverName;

public:
    Rickshaw(string _make, string _model, int _year,  Engine _engine, string _driverName);

    void display() override;
    json toJson()   override;
    friend ostream& operator<<(ostream& os, const Rickshaw& rickshaw);
};
#endif //UNTITLED_RICKSHAW_H
