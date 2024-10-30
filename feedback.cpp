#include <iostream>
#include "feedback.h"
using namespace std;
Feedback::Feedback(string driver, string vehicle) : driver_feedback(driver), vehicle_feedback(vehicle) {}

string Feedback::getDriverFeedback() const {
    return driver_feedback;
}

string Feedback::getVehicleFeedback() const {
    return vehicle_feedback;
}

ostream& operator<<(ostream& os, const Feedback& feedback) {
    os << "Driver Feedback: " << feedback.driver_feedback << endl;
    os << "Vehicle Feedback: " << feedback.vehicle_feedback << endl;
    return os;
}
