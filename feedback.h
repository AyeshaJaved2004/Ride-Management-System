#ifndef MY_PROJECT_FEEDBACK_H
#define MY_PROJECT_FEEDBACK_H
#include <iostream>
using namespace std;
#include <string>
class Feedback {
private:
    string driver_feedback;
    string vehicle_feedback;

public:
    Feedback(string driver, string vehicle);

    string getDriverFeedback() const;
    string getVehicleFeedback() const;

    friend ostream& operator<<(ostream& os, const Feedback& feedback);
};
#endif //MY_PROJECT_FEEDBACK_H
