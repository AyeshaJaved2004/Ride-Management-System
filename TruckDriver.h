//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_TRUCKDRIVER_H
#define NEW_FOLDER_TRUCKDRIVER_H
#include "Driver.h"
#include "CommercialLicense.h"
#include <string>
using namespace std;

//template class
template<typename LicenseType>
class TruckDriver : public Driver {   //inheritance
    CommercialLicense* license;
public:
    TruckDriver(string name, int age, CommercialLicense* license);
    void displayInfo() const override; // Polymorphism
};
#endif //NEW_FOLDER_TRUCKDRIVER_H
