//
// Created by GLOBAL LAPTOP BAZAR on 5/10/2024.
//

#ifndef UNTITLED_VEHICLESTATISTICS_H
#define UNTITLED_VEHICLESTATISTICS_H
#include <iostream>
#include <vector>
#include<string>

using namespace std;
template<typename T>
class VehicleStatistics {
private:
    vector<T> data;

public:
    VehicleStatistics();

    void addData( T value);

    double calculateAverage() ;

    T findMaximum() ;

    T findMinimum() ;
};
//#include "VehicleStatistics.h"
#endif //UNTITLED_VEHICLESTATISTICS_H
