//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_RICKSHAWDRIVER_H
#define NEW_FOLDER_RICKSHAWDRIVER_H
#include "Driver.h"
#include "NonCommercialLicense.h"
#include <string>
using namespace std;

class RickshawDriver : public Driver {
private:
    string rickshawModel;
    string rickshawNumber;
public:
    RickshawDriver(string name, int age, NonCommercialLicense* license, string rickshawModel, string rickshawNumber);
    void displayInfo() const override;
};
#endif //NEW_FOLDER_RICKSHAWDRIVER_H
