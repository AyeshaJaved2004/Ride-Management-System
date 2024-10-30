//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//

#ifndef UNTITLED_TRUCK_H
#define UNTITLED_TRUCK_H
#include "Vehicle.h"
#include "nlohmann/json.hpp"
#include <string>
#include<iostream>
//#include<iostream>
//#include<string>
using namespace std;

using namespace std;
class Truck : public Vehicle {
private:
    int capacity; // in tons
    int currentLoad;

public:
     Truck(string _make, string _model, int _year, const Engine& _engine, int _capacity)
            : Vehicle("Truck", _make, _model, _year, _engine), capacity(_capacity), currentLoad(0) {}
    void display()  override;
    void addLoad(int load);
    bool isOverloaded() ;
    int remainingCapacity() ;
    bool isFullyLoaded() ;
    void adjustCapacity(int newCapacity);
    void updateLoad(int newLoad);

    void start() ;
    void stop() ;
    json toJson() ;
};
#endif //UNTITLED_TRUCK_H
