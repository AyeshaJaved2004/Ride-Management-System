//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_COMMERCIALLICENSE_H
#define NEW_FOLDER_COMMERCIALLICENSE_H
#include "License.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class CommercialLicense : public License {
private:
    string category;
    vector<string> endorsements;
    map<string, string> restrictions;
public:
    CommercialLicense(string number, string expirationDate, string category);
    string getLicenseType() const override;
    void displayInfo() const override;
    json JsonW() const;  //convert data into json representation
};

#endif //NEW_FOLDER_COMMERCIALLICENSE_H
