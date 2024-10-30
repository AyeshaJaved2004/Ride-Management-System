//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//

#ifndef UNTITLED_VEHICLE_H
#define UNTITLED_VEHICLE_H
#include <string>
#include "Engine.h"
#include "nlohmann/json.hpp"
#include "SafetyFeatures.h"
#include <iostream>

using namespace std;

using json = nlohmann::json;

class Vehicle {
private:
    string type;
    bool isStarted;
    const Engine* engine;
    SafetyFeatures safetyFeatures;
public:
    string make;
    string model;

    Vehicle( const char *_type,  string _make,  string _model, int _year,  Engine _engine);
    virtual ~Vehicle();
    void setSafetyFeatures(SafetyFeatures safety) { safetyFeatures = safety; }
    SafetyFeatures getSafetyFeatures() { return safetyFeatures; }

    void start();
    void stop();
    bool isVehicleStarted() ;
    virtual void display() ;
    virtual json toJson() ;

    int year;
};
#endif //UNTITLED_VEHICLE_H
