#include <iostream>
#include "location.h"
using namespace std;
Location::Location() : name(""), address("") {}

Location::Location(const string& name, const string& address) : name(name), address(address) {}

string Location::getName() const {
    return name;
}

string Location::getAddress() const {
    return address;
}

string Location::getInfo(const string& key) const {
    try {
        return additionalInfo.at(key);
    } catch (const out_of_range& e) {
        return "";
    }
}

void Location::setName(const std::string& newName) {
    name = newName;
}

void Location::setAddress(const string& newAddress) {
    address = newAddress;
}

void Location::setInfo(const string& key, const string& value) {
    additionalInfo[key] = value;
}