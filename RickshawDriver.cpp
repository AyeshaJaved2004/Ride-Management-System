//
// Created by user on 5/9/2024.
//

#include "RickshawDriver.h"
#include "NonCommercialLicense.h"
#include <iostream>
#include <string>
using namespace std;

RickshawDriver::RickshawDriver(string name, int age, NonCommercialLicense* license, string rickshawModel, string rickshawNumber) : Driver(name, age, license)
{
    this->rickshawModel = rickshawModel;
    this->rickshawNumber = rickshawNumber;
}
void RickshawDriver::displayInfo() const
{
    cout << "Rickshaw Driver Information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "License Type: " << license->getLicenseType() << endl;
    license->displayInfo();
    cout << "Rickshaw Model: " << rickshawModel << endl;
    cout << "Rickshaw Number: " << rickshawNumber << endl;
}