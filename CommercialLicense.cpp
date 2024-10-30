//
// Created by user on 5/9/2024.
//

#include "CommercialLicense.h"
#include <string>
#include <iostream>
using namespace std;

CommercialLicense::CommercialLicense(string number, string expirationDate, string category) : License(number, expirationDate)
{
    this->category = category;
    endorsements.push_back("Endorsement T (Double/Triples)");
    endorsements.push_back("Endorsement P (Passenger Transport)");
    restrictions["Restriction A"] = "With corrective lenses";
    restrictions["Restriction B"] = "A licensed driver 21 years of age or older (LOFS) must be in the front seat";
    restrictions["Restriction C"] = "Speed not to exceed 45 mph";
    restrictions["Restriction D"] = "Daytime driving only";
}
string CommercialLicense::getLicenseType() const
{
    return "Commercial";
}
void CommercialLicense::displayInfo() const
{
    License::displayInfo();
    cout << "Category: " << category << endl;
    cout << endl;
    cout << "Endorsements:" << endl;
    for (const auto& endorsement : endorsements) {
        cout << endorsement << endl;
    }
    cout << endl;

    cout << "Restrictions:" << endl;
    for (const auto& pair : restrictions) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
json CommercialLicense::JsonW() const {
    json licenseJson = {
            {"Number", number},
            {"ExpirationDate", expirationDate},
            {"Category", category}
    };
    return licenseJson;
}