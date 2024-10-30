//
// Created by user on 5/10/2024.
//

#ifndef NEW_FOLDER_DRIVERMANAGER_H
#define NEW_FOLDER_DRIVERMANAGER_H
#include <string>
#include "nlohmann/json.hpp"
#include "ManagerInfo.h"

using namespace std;
using json = nlohmann::json;

//singleton class
class DriverManager {
private:
    static DriverManager* instance;
    string filename;
    ManagerInfo managerInfo;  //composition
    DriverManager(const string& filename, const ManagerInfo managerInfo); //singleton constructor

public:
    static DriverManager& getInstance(string filename, const ManagerInfo& managerInfo);

    void saveDriversToFile(json& drivers);
    void displayDriver();
    json loadDriversFromFile();
    void displayAvailableDrivers();
    void bookDriver(json& drivers, const string& name) ;
    void displayUnavailableDrivers();
    void unbookDriver(json& drivers, const string& name) ;
};
#endif //NEW_FOLDER_DRIVERMANAGER_H
