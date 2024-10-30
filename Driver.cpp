//
// Created by user on 5/9/2024.
//


#include "Driver.h"
#include <string>
#include <iostream>
using namespace std;

Driver::Driver()
{
    name = "";
    age = 0;
    license = nullptr;
    booked = false;
}

Driver::Driver(std::string name, int age, License* license)
{
    this->name = name;
    this->age = age;
    this->license = license;
    booked = false;
}
bool Driver::isBooked() const
{
    return booked;
}