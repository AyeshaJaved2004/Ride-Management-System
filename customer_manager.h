#ifndef MY_PROJECT_CUSTOMER_MANAGER_H
#define MY_PROJECT_CUSTOMER_MANAGER_H
#include <iostream>
#include "customer.h"
#include <vector>
using namespace std;
class CustomerManager {
private:
    vector<Customer<int>*> customers;
    static CustomerManager* instance;

    CustomerManager() {} // Private constructor to prevent instantiation from outside

public:
    static CustomerManager* getInstance();

    void addCustomer(Customer<int>* customer);

    void saveAllToJson() const;
};
#endif //MY_PROJECT_CUSTOMER_MANAGER_H
