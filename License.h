//
// Created by user on 5/9/2024.
//

#ifndef NEW_FOLDER_LICENSE_H
#define NEW_FOLDER_LICENSE_H
#include <string>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

class License {
protected:
    string number;
    string expirationDate;
public:
    License(string number, string expirationDate);
    virtual string getLicenseType() const = 0; //virtual function
    virtual void displayInfo() const; //virtual function
};
#endif //NEW_FOLDER_LICENSE_H
