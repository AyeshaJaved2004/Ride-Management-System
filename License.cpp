//
// Created by user on 5/9/2024.
//

#include "License.h"
#include <string>
#include <iostream>
using namespace std;


License::License(string number, string expirationDate)
{
    this->number = number;
    this->expirationDate = expirationDate;
}
void License::displayInfo() const
{
    cout << "License Number: " << number << endl;
    cout << "Expiration Date: " << expirationDate << endl;
}
