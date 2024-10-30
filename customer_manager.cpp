#include <iostream>
#include "customer_manager.h"
using namespace std;
CustomerManager* CustomerManager::instance = nullptr;

CustomerManager* CustomerManager::getInstance() {
    if (!instance) {
        instance = new CustomerManager();
    }
    return instance;
}

void CustomerManager::addCustomer(Customer<int>* customer) {
    customers.push_back(customer);
}

void CustomerManager::saveAllToJson() const {
    for (const auto& customer : customers) {
        string filename = customer->getName() + "_customer.json";
        customer->saveToJson(filename);
    }
}