//
// Created by user on 5/9/2024.
//

#include "CarDriver.h"
#include "NonCommercialLicense.h"
#include <string>
#include <iostream>
using namespace std;

CarDriver::CarDriver(string name, int age, NonCommercialLicense* license) : Driver(name, age, license) {}

void CarDriver::displayInfo() const
{
    cout << "Car Driver Information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "License Type: " << license->getLicenseType() << endl;
    license->displayInfo();
}