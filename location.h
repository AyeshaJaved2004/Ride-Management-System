
#ifndef MY_PROJECT_LOCATION_H
#define MY_PROJECT_LOCATION_H
#include <iostream>
#include <string>
#include <map>
using namespace std;
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Location {
private:
    string name;
    string address;
    map<string, string> additionalInfo;

public:
    Location();
    Location(const string& name, const string& address);

    string getName() const;
    string getAddress() const;
    string getInfo(const string& key) const;

    // Public setter functions
    void setName(const string& newName);
    void setAddress(const string& newAddress);
    void setInfo(const string& key, const string& value);
};
#endif //MY_PROJECT_LOCATION_H
