//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_DRIVE_H
#define NEW_FOLDER_DRIVE_H
#include <string>
#include "License.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

class Driver {
protected:
    string name;
    int age;
    License* license; //aggregation
    bool booked;
public:
    Driver();
    Driver(string name, int age, License* license);
    virtual void displayInfo() const = 0; //Polymorphism
    bool isBooked() const;
};
#endif //NEW_FOLDER_DRIVE_H
