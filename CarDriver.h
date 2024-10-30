//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_CARDRIVER_H
#define NEW_FOLDER_CARDRIVER_H
#include "Driver.h"
#include "NonCommercialLicense.h"
#include <string>
using namespace std;


class CarDriver : public Driver {
public:
    CarDriver(string name, int age, NonCommercialLicense* license);
    void displayInfo() const override;
};
#endif //NEW_FOLDER_CARDRIVER_H
