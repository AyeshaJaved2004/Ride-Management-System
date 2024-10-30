//
// Created by user on 5/9/2024.
//

#include "NonCommercialLicense.h"
#include <string>
#include <iostream>
using namespace std;

NonCommercialLicense::NonCommercialLicense(string number, string expirationDate, string vehicleType): License(number, expirationDate)
{
    this->vehicleType = vehicleType;
}
string NonCommercialLicense::getLicenseType() const
{
    return "Non-Commercial";
}
void NonCommercialLicense::displayInfo() const
{
    License::displayInfo();
    cout << "Vehicle Type: " << vehicleType << endl;
}
json NonCommercialLicense::JsonWritting() const
{
    json licenseJson = {
            {"Number", number},
            {"ExpirationDate", expirationDate},
            {"VehicleType", vehicleType}
    };
    return licenseJson;
}