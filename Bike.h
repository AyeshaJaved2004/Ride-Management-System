//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//

#ifndef UNTITLED_BIKE_H
#define UNTITLED_BIKE_H
#include "Vehicle.h"
#include "nlohmann/json.hpp"
#include<string>
using namespace std;

class Bike : public Vehicle {
private:
    string bikeType;

public:
    // Constructor
    Bike(string _make, string _model, int _year, Engine _engine, string _bikeType);

    // Getter for bikeType
    string getBikeType()  {
        return bikeType;
    }

    // Setter for bikeType
    void setBikeType(string _bikeType) {
        bikeType = _bikeType;
    }

    // Display function
    void display() ;

    // To JSON function
    json toJson() ;
};
#endif //UNTITLED_BIKE_H
