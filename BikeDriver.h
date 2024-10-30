//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_BIKEDRIVER_H
#define NEW_FOLDER_BIKEDRIVER_H
#include "Driver.h"
#include "NonCommercialLicense.h"
#include <string>
using namespace std;

class BikeDriver : public Driver {
public:
    BikeDriver(string name, int age, NonCommercialLicense* license);  //association
    void displayInfo() const override;
};
#endif //NEW_FOLDER_BIKEDRIVER_H
