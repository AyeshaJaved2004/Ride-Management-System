//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_NONCOMMERCIALLICENSE_H
#define NEW_FOLDER_NONCOMMERCIALLICENSE_H
#include "License.h"
#include <string>
using namespace std;

class NonCommercialLicense : public License {
private:
    string vehicleType;
public:
    NonCommercialLicense(string number, string expirationDate, string vehicleType);
    string getLicenseType() const override;
    void displayInfo() const override;
    json JsonWritting() const;
};
#endif //NEW_FOLDER_NONCOMMERCIALLICENSE_H
