#ifndef MY_PROJECT_FARE_H
#define MY_PROJECT_FARE_H
#include<iostream>
using namespace std;
class Fare {
private:
    float base_fare;
    float discount_rate;

public:
    Fare(float base_fare, float discount_rate);

    float calculateTotal(float original_fare) const;

    // Overloading << operator for printing Fare
    friend ostream& operator<<(ostream& os, const Fare& fare);
};
#endif //MY_PROJECT_FARE_H
