//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//
#include "Truck.h"
#include <iostream>
//#include<iostream>
#include<string>
using namespace std;
void Truck::display()  {
    Vehicle::display();
    cout << "Capacity: " << capacity << " tons" << endl;
    cout << "Current Load: " << currentLoad << " tons" << endl;
}

void Truck::addLoad(int load) {
    currentLoad += load;
}

bool Truck::isOverloaded() {
    return currentLoad > capacity;
}

void Truck::start() {
    Vehicle::start();
    cout << "Truck started." << endl;
}

void Truck::stop() {
    Vehicle::stop();
    cout << "Truck stopped." << endl;
}
// Function to calculate and return the remaining capacity of the truck
int Truck:: remainingCapacity()  {
    return capacity - currentLoad;
}

// Function to check if the truck is fully loaded
bool Truck :: isFullyLoaded()  {
    return currentLoad == capacity;
}

// Function to adjust the capacity of the truck
void Truck :: adjustCapacity(int newCapacity) {
    capacity = newCapacity;
}

// Function to update the current load of the truck
void Truck :: updateLoad(int newLoad) {
    currentLoad = newLoad;
}

json Truck::toJson()  {
    return {
            {"type", "Truck"},
            {"details", Vehicle::toJson()},
            {"capacity", capacity},
            {"currentLoad", currentLoad}
    };
}