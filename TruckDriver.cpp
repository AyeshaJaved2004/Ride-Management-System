//
// Created by user on 5/9/2024.
//

#include "TruckDriver.h"
#include "CommercialLicense.h"
#include <iostream>
#include <string>
using namespace std;

template<typename LicenseType>
TruckDriver<LicenseType>::TruckDriver(string name, int age, CommercialLicense* license) : Driver(name, age, license)
{
    this->license = license;
}
template<typename LicenseType>
void TruckDriver<LicenseType>::displayInfo() const
{
    cout << "Truck Driver Information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "License Type: " << license->getLicenseType() << endl;
    license->displayInfo();
}
template class TruckDriver<CommercialLicense>;
