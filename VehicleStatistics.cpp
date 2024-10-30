//
// Created by GLOBAL LAPTOP BAZAR on 5/10/2024.
//
#include "VehicleStatistics.h"
#include <iostream>

using namespace std;

template<typename T>
VehicleStatistics<T>::VehicleStatistics() {}

template<typename T>
void VehicleStatistics<T>::addData( T value) {
    data.push_back(value);
}

template<typename T>
double VehicleStatistics<T>::calculateAverage()  {
    if (data.empty()) {
        cerr << "Error: No data available." << endl;
        return 0.0;
    }

    double sum = 0.0;
    for ( auto val : data) {
        sum += val;
    }
    return sum / data.size();
}

template<typename T>
T VehicleStatistics<T>::findMaximum()  {
    if (data.empty()) {
        cerr << "Error: No data available." << endl;
        return T();
    }

    T maxVal = data[0];
    for ( auto val : data) {
        if (val > maxVal) {
            maxVal = val;
        }
    }
    return maxVal;
}

template<typename T>
T VehicleStatistics<T>::findMinimum()  {
    if (data.empty()) {
        cerr << "Error: No data available." << endl;
        return T();
    }

    T minVal = data[0];
    for ( auto val : data) {
        if (val < minVal) {
            minVal = val;
        }
    }
    return minVal;
}

template class VehicleStatistics<int>;