#ifndef MY_PROJECT_CUSTOMER_H
#define MY_PROJECT_CUSTOMER_H
#include<iostream>
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include "feedback.h"
#include "fare.h"
#include <string>

template<typename T>
class Customer {
protected:
    string name;
    int age;
    float wallet_balance;
    vector<Feedback> feedbacks;
    Fare fare;
public:
    Customer(string n, int a, float balance,float base_fare, float discount_rate);
    string getName() const;
    void addFeedback(const Feedback& feedback);
    void displayFeedbacks() const;
    virtual float calculateFare(float original_fare, const Fare& fare) const = 0;
    virtual void saveToJson(const string& filename) const;

};
template<typename T>
class RegularCustomer : public Customer<T> {
public:
    RegularCustomer(string n, int a, float balance,float base_fare, float discount_rate);
    float calculateFare(float original_fare, const Fare& fare) const override;
};
template<typename T>
class StudentCustomer : public Customer<T> {
public:
    StudentCustomer(string n, int a, float balance,float base_fare, float discount_rate);
    float calculateFare(float original_fare, const Fare& fare) const override;
};
template<typename T>
class SeniorCitizenCustomer : public Customer<T> {
public:
    SeniorCitizenCustomer(string n, int a, float balance,float base_fare, float discount_rate);
    float calculateFare(float original_fare, const Fare& fare) const override;
};
template<typename T>
class VIPCustomer : public Customer<T> {
private:
    int loyaltyPoints;
public:
    VIPCustomer(string n, int a, float balance,float base_fare, float discount_rate);
    float calculateFare(float original_fare, const Fare& fare) const override;
    void redeemLoyaltyPoints(RegularCustomer<T>& regularCustomer);
};
#endif //MY_PROJECT_CUSTOMER_H
