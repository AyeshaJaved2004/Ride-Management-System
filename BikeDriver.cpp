//
// Created by user on 5/9/2024.
//

#include "BikeDriver.h"
#include "NonCommercialLicense.h"
#include <string>
#include <iostream>
using namespace std;

BikeDriver::BikeDriver(string name, int age, NonCommercialLicense* license): Driver(name, age, license) {}

void BikeDriver::displayInfo() const
{
    cout << "Bike Driver Information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "License Type: " << license->getLicenseType() << endl;
    license->displayInfo();
}
