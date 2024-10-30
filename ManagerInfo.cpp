//
// Created by user on 5/10/2024.
//

#include "ManagerInfo.h"

using namespace std;

ManagerInfo::ManagerInfo()
{
    managerName = "";
    managerAge = 0;
}
ManagerInfo::ManagerInfo(string name, int age)
{
    managerName = name;
    managerAge = age;
}

ostream& operator<<(ostream& os, const ManagerInfo& mag)
{
    os << "Manager Name: " << mag.managerName << endl;
    os << "Manager Age: " << mag.managerAge << endl;
    return os;
}