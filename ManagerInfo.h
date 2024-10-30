//
// Created by user on 5/10/2024.
//

#ifndef NEW_FOLDER_MANAGERINFO_H
#define NEW_FOLDER_MANAGERINFO_H
#include <iostream>
#include <string>

using namespace std;

class ManagerInfo {
private:
    string managerName;
    int managerAge;

public:
    ManagerInfo();
    ManagerInfo(string name, int age);
    friend ostream& operator<<(ostream& os, const ManagerInfo& mag);  //operator ovverloading
};

#endif //NEW_FOLDER_MANAGERINFO_H
