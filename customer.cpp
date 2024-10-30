#include <iostream>
#include "customer.h"
#include "fare.h"
#include "feedback.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

template<typename T>
Customer<T>::Customer(string n, int a, float balance, float base_fare, float discount_rate) : name(n), age(a), wallet_balance(balance), fare(base_fare, discount_rate) {}

template<typename T>
string Customer<T>::getName() const {
    return name;
}

template<typename T>
void Customer<T>::addFeedback(const Feedback& feedback) {
    feedbacks.push_back(feedback);
}

template<typename T>
void Customer<T>::displayFeedbacks() const {
    for (const auto& feedback : feedbacks) {
        cout << feedback;
    }
}

template<typename T>
void Customer<T>::saveToJson(const string& filename) const {
    json j;
    j["Name"] = name;
    j["Age"] = age;
    j["WalletBalance"] = wallet_balance;

    ofstream file(filename);
    file << setw(4) << j;
}

template<typename T>
RegularCustomer<T>::RegularCustomer(string n, int a, float balance, float base_fare, float discount_rate) : Customer<T>(n, a, balance, base_fare,  discount_rate) {}

template<typename T>
float RegularCustomer<T>::calculateFare(float original_fare, const Fare& fare) const {
    return fare.calculateTotal(original_fare);
}
template<typename T>
StudentCustomer<T>::StudentCustomer(string n, int a, float balance, float base_fare, float discount_rate) : Customer<T>(n, a, balance, base_fare,  discount_rate) {}

template<typename T>
float StudentCustomer<T>::calculateFare(float original_fare, const Fare& fare) const {
    float discounted_fare = original_fare * (1.0 - 0.15); // Applying 15% discount
    return fare.calculateTotal(discounted_fare);
}

template<typename T>
SeniorCitizenCustomer<T>::SeniorCitizenCustomer(string n, int a, float balance, float base_fare, float discount_rate) : Customer<T>(n, a, balance, base_fare, discount_rate) {}

template<typename T>
float SeniorCitizenCustomer<T>::calculateFare(float original_fare, const Fare& fare) const {
    float discounted_fare = original_fare * (1.0 - 0.10); // Applying 10% discount
    return fare.calculateTotal(discounted_fare);
}

template<typename T>
VIPCustomer<T>::VIPCustomer(string n, int a, float balance, float base_fare, float discount_rate) : Customer<T>(n, a, balance, base_fare, discount_rate), loyaltyPoints(0) {}

template<typename T>
void VIPCustomer<T>::redeemLoyaltyPoints(RegularCustomer<T>& regularCustomer) {
    if (loyaltyPoints >= 100) { // Assuming 100 points can be redeemed for an offer
        // Provide exclusive offer to regular customer
        regularCustomer.addFeedback(Feedback("Exclusive Offer", "Redeemed with VIP loyalty points"));
        // Reset loyalty points
        loyaltyPoints -= 100;
    } else {
        std::cout << "Insufficient loyalty points to redeem an offer." << std::endl;
    }
}

template<typename T>
float VIPCustomer<T>::calculateFare(float original_fare, const Fare& fare) const {
    return fare.calculateTotal(original_fare);
}

template class Customer<int>;
template class RegularCustomer<int>;
template class StudentCustomer<int>;
template class SeniorCitizenCustomer<int>;
template class VIPCustomer<int>;