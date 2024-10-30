#include <iostream>
#include "fare.h"
using namespace std;
Fare::Fare(float base_fare, float discount_rate) : base_fare(base_fare), discount_rate(discount_rate) {}

float Fare::calculateTotal(float original_fare) const {
    float discounted_fare = original_fare * (1.0 - discount_rate);
    return discounted_fare > base_fare ? discounted_fare : base_fare;
}

ostream& operator<<(ostream& os, const Fare& fare) {
    os << "Base Fare: " << fare.base_fare << ", Discount Rate: " << fare.discount_rate;
    return os;
}