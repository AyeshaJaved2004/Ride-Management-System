//
// Created by user on 5/10/2024.
//

#include "DriverManager.h"
#include "ManagerInfo.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


DriverManager* DriverManager::instance = nullptr;

DriverManager::DriverManager(const string& filename, const ManagerInfo managerInfo)
{
    this->filename = filename;
    this->managerInfo = managerInfo;
}

DriverManager& DriverManager::getInstance(string filename,const ManagerInfo& managerInfo)
{
    if (instance == nullptr)
    {
        instance = new DriverManager(filename,managerInfo);
    }
    return *instance;
}

void DriverManager::saveDriversToFile(json& drivers)
{
    json updatedDrivers = drivers;
    for (auto& driver : updatedDrivers)
    {
        if (!driver.contains("Booked"))
        {
            driver["Booked"] = false;
        }
    }
    ofstream file(filename);
    if (file.is_open())
    {
        file << setw(4) << updatedDrivers << endl;
        cout << "Drivers saved to file: " << filename << endl;
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

void DriverManager::displayDriver()
{
    ifstream file(filename);
    json drivers;

    if (file.is_open()) {
        file >> drivers;
        file.close();

        for (const auto& driver : drivers)
        {
            cout << "Name: " << driver["Name"] << endl;
            cout << "Age: " << driver["Age"] << endl;
            if (driver.find("License") != driver.end())
            {
                cout << "License Number: " << driver["License"]["Number"] << endl;
                cout << "License Expiration Date: " << driver["License"]["ExpirationDate"] << endl;
            }
            if (driver.find("RickshawModel") != driver.end() && driver.find("RickshawNumber") != driver.end())
            {
                cout << "Rickshaw Model: " << driver["RickshawModel"] << endl;
                cout << "Rickshaw Number: " << driver["RickshawNumber"] << endl;
            }
            cout << endl;
        }
    } else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

json DriverManager::loadDriversFromFile()
{
    ifstream file(filename);
    json drivers;
    if (file.is_open()) {
        file >> drivers;
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
    return drivers;
}

void DriverManager::displayAvailableDrivers()
{
    ifstream file(filename);
    json drivers;

    if (file.is_open())
    {
        file >> drivers;
        file.close();
        cout << "Available Drivers:" << endl;
        for (const auto& driver : drivers)
        {
            bool booked = false;
            if (driver.contains("Booked") && driver["Booked"]==true)
            {
                booked = driver["Booked"];
            }
            if (!booked)
            {
                cout << "Name: " << driver["Name"] << endl;
                cout << "Age: " << driver["Age"] << endl;
                if (driver.contains("License"))
                {
                    cout << "License Number: " << driver["License"]["Number"] << endl;
                    cout << "License Expiration Date: " << driver["License"]["ExpirationDate"] << endl;
                }
                if (driver.contains("RickshawModel") && driver.contains("RickshawNumber"))
                {
                    cout << "Rickshaw Model: " << driver["RickshawModel"] << endl;
                    cout << "Rickshaw Number: " << driver["RickshawNumber"] << endl;
                }
                cout << endl;
            }
        }
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

void DriverManager::bookDriver(json& drivers, const string& name)
{
    for (auto& driver : drivers)
    {
        if (driver["Name"] == name)
        {
            if (!driver.contains("Booked") || !driver["Booked"]==true)
            {
                driver["Booked"] = true;
                cout << "Driver booked: " << name << endl;
                saveDriversToFile(drivers);
                return;
            }
            else if (!driver["Booked"]!=false)
            {
                driver["Booked"] = true;
                cout << "Driver booked: " << name << endl;
                saveDriversToFile(drivers);
                return;
            }
            else
            {
                cout << "Driver already booked." <<endl;
                return;
            }
        }
    }
    cout << "Driver not found." << endl;
}

void DriverManager::displayUnavailableDrivers()
{
    ifstream file(filename);
    json drivers;
    if (file.is_open())
    {
        file >> drivers;
        file.close();

        cout << "Unavailable Drivers:" << endl;
        for (const auto& driver : drivers)
        {
            bool booked = false;
            if (driver.contains("Booked") && driver["Booked"]==true)
            {
                booked = driver["Booked"];
            }
            if (booked)
            {
                cout << "Name: " << driver["Name"] << endl;
                cout << "Age: " << driver["Age"] << endl;
                if (driver.contains("License"))
                {
                    cout << "License Number: " << driver["License"]["Number"] << endl;
                    cout << "License Expiration Date: " << driver["License"]["ExpirationDate"] << endl;
                }
                if (driver.contains("RickshawModel") && driver.contains("RickshawNumber"))
                {
                    cout << "Rickshaw Model: " << driver["RickshawModel"] << endl;
                    cout << "Rickshaw Number: " << driver["RickshawNumber"] << endl;
                }
                cout << endl;
            }
        }
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

void DriverManager::unbookDriver(json& drivers, const string& name)
{
    for (auto& driver : drivers) {
        if (driver["Name"] == name) {
            if (driver.contains("Booked") && driver["Booked"]==true && driver["Booked"]!=false)
            {
                driver["Booked"] = false;
                cout << "Driver unbooked: " << name << endl;
                saveDriversToFile(drivers);
                return;
            }
            else
            {
                cout << "Driver is not currently booked." << endl;
                return;
            }
        }
    }
    cout << "Driver not found." <<endl;
}