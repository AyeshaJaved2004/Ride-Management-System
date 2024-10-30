#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "nlohmann/json.hpp"
#include "Driver.h"
#include "TruckDriver.h"
#include "CarDriver.h"
#include "BikeDriver.h"
#include "RickshawDriver.h"
#include "DriverManager.h"
#include "ManagerInfo.h"
#include "location.h"
#include "customer.h"
#include "fare.h"
#include "feedback.h"
#include "customer_manager.h"
#include <vector>
#include "Engine.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "Rickshaw.h"



using json = nlohmann::json;
using namespace std;
class VehicleManager {
private:
    static VehicleManager* instance;
    vector<Vehicle*> vehicles;
    VehicleManager() {
    }


public:
    static VehicleManager* getInstance() {
        if (instance == nullptr) {
            instance = new VehicleManager();
        }
        return instance;
    }
    ~VehicleManager() {
        for (auto vehicle : vehicles)
            delete vehicle;
    }
    Vehicle* searchVehicle( string make,  string model)  {
        for ( auto vehicle : vehicles) {
            if (vehicle->make == make && vehicle->model == model) {
                return vehicle;
            }
        }
        return nullptr; // Return nullptr if vehicle not found
    }
    void displayAvailableVehicles()  {
        for ( auto vehicle : vehicles) {
            if (!vehicle->isVehicleStarted()) {
                vehicle->display();
                cout << endl;
            }
        }
    }
    void updateVehicleInfo( string make,  string model,  string newMake,  string newModel, int newYear) {
        for (auto vehicle : vehicles) {
            if (vehicle->make == make && vehicle->model == model) {
                vehicle->make = newMake;
                vehicle->model = newModel;
                vehicle->year = newYear;
                cout << "Vehicle information updated successfully." << endl;
                return;
            }
        }
        cout << "Vehicle not found or not available for updating." << endl;
    }

    void removeVehicle( string make,  string model) {
        for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
            if ((*it)->make == make && (*it)->model == model) {
                delete *it; // Free memory of the vehicle being removed
                vehicles.erase(it); // Remove the pointer from the vector
                cout << "Vehicle removed successfully." << endl;
                return;
            }
        }
        cout << "Vehicle not found or not available for removal." << endl;
    }
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }
    bool isVehicleAvailable( string make,  string model)  {
        for ( auto vehicle : vehicles) {
            if (vehicle->make == make && vehicle->model == model) {
                cout << "Vehicle found. It is available for a ride." << endl;
                return true;
            }
        }
        cout << "Vehicle not found or not available." << endl;
        return false;
    }

    void displayAll()  {
        for ( auto vehicle : vehicles) {
            vehicle->display();
            cout << endl;
        }
    }

    json toJson()  {
        json j;
        for ( auto vehicle : vehicles) {
            j.push_back(vehicle->toJson());
        }
        return j;
    }

    void saveToJson( string filename)  {
        ofstream file(filename);
        if (file.is_open()) {
            file << toJson().dump(4); // Pretty print with 4 spaces
            file.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
};


VehicleManager* VehicleManager::instance = nullptr;

void displayMenu() {
    cout << "===== Vehicle Management System =====" << endl;
    cout << "1. Display all vehicles" << endl;
    cout << "2. Add a new vehicle" << endl;
    cout << "3. Remove a vehicle" << endl;
    cout << "4. Check if a vehicle is available" << endl;
    cout << "5. Save vehicles to JSON file" << endl;
    cout << "6. Exit" << endl;
    cout << "7. search vehicle" << endl;
    cout << "8. Available vehicles " << endl;
    cout << "9. update " << endl;
    cout << "10. friend function and operator overloading " << endl;

    cout << "=====================================" << endl;
}

int main()
{
    int select;
    cout << "-----TRAVEL MANAGEMENT SYSTEM-----" << endl;
    do {
        cout << "Enter 1 for customer " << endl;
        cout << "Enter 2 for vehicle " << endl;
        cout << "Enter 3 for Driver " << endl;
        cin >> select;
        switch (select) {
            case 1: {
                Fare fare(50.0, 0.1); // Base fare of $50 with 10% discount

                // Create locations for pickup and dropoff
                Location pickup, dropoff;

                cout << "Enter pickup location details:" << endl;
                cout << "Name: ";
                string pickupName;
                getline(cin, pickupName);
                pickup.setName(pickupName);
                cout << "Address: ";
                string pickupAddress;
                getline(cin, pickupAddress);
                pickup.setAddress(pickupAddress);

                cout << "Enter dropoff location details:" << endl;
                cout << "Name: ";
                string dropoffName;
                getline(cin, dropoffName);
                dropoff.setName(dropoffName);
                cout << "Address: ";
                string dropoffAddress;
                getline(cin, dropoffAddress);
                dropoff.setAddress(dropoffAddress);

                // Create customers of different types
                RegularCustomer<int> regular("John", 30, 100.0, 50.0, 0.1); // Here, int is the template parameter
                StudentCustomer<int> student("Alice", 20, 50.0, 50.0, 0.1); // Here, int is the template parameter
                SeniorCitizenCustomer<int> senior("Bob", 65, 80.0, 50.0, 0.1); // Here, int is the template parameter
                VIPCustomer<int> vip("Emily", 40, 200.0, 50.0, 0.1); // Here, int is the template parameter

                // Add customers to CustomerManager
                CustomerManager *manager = CustomerManager::getInstance();
                manager->addCustomer(&regular);
                manager->addCustomer(&student);
                manager->addCustomer(&senior);
                manager->addCustomer(&vip);

                // Add feedback for customers
                regular.addFeedback(Feedback("Good driving", "Clean vehicle"));
                student.addFeedback(Feedback("Punctual", "Comfortable ride"));
                senior.addFeedback(Feedback("Polite driver", "Smooth ride"));
                vip.addFeedback(Feedback("Excellent service", "Luxurious vehicle"));

                int choice;
                do {
                    cout << "Menu:" << endl;
                    cout << "1. Display Feedbacks" << endl;
                    cout << "2. Calculate Fares" << endl;
                    cout << "3. Save Customer Data to JSON files" << endl;
                    cout << "4. Redeem VIP Loyalty Points for Regular Customer" << endl; // New option
                    cout << "5. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Regular Customer Feedbacks:" << endl;
                            regular.displayFeedbacks();
                            cout << endl;
                            cout << "Student Customer Feedbacks:" << endl;
                            student.displayFeedbacks();
                            cout << endl;
                            cout << "Senior Citizen Customer Feedbacks:" << endl;
                            senior.displayFeedbacks();
                            cout << endl;
                            cout << "VIP Customer Feedbacks:" << endl;
                            vip.displayFeedbacks();
                            cout << endl;
                            break;
                        case 2:
                            float original_fare;
                            cout << "Enter original fare amount: $";
                            cin >> original_fare;
                            cout << "Regular Customer Fare: $" << regular.calculateFare(original_fare, fare) << endl;
                            cout << "Student Customer Fare: $" << student.calculateFare(original_fare, fare) << endl;
                            cout << "Senior Citizen Customer Fare: $" << senior.calculateFare(original_fare, fare)
                                 << endl;
                            cout << "VIP Customer Fare: $" << vip.calculateFare(original_fare, fare) << endl;
                            break;
                        case 3:
                            manager->saveAllToJson();
                            cout << "Customer data saved to JSON files." << endl;
                            break;
                        case 4:
                            vip.redeemLoyaltyPoints(regular); // Redeem VIP loyalty points for regular customer
                            break;
                        case 5:
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                            break;
                    }
                } while (choice != 5);

                delete manager;
            }
            case 2: {
                VehicleManager* manager = VehicleManager::getInstance();

                int choice;
                do {
                    displayMenu();
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch(choice) {
                        case 1: {
                            manager->displayAll();
                            break;
                        }
                        case 2: {
                            string type, make, model;
                            int year, doors, capacity;
                            string bikeType, driverName;
                            int horsepower;

                            cout << "Enter vehicle type (Car/Bike/Truck/Rickshaw): ";
                            cin >> type;
                            cout << "Enter make: ";
                            cin >> make;
                            cout << "Enter model: ";
                            cin >> model;
                            cout << "Enter year: ";
                            cin >> year;

                            if (type == "Car") {
                                cout << "Enter number of doors: ";
                                cin >> doors;
                                cout << "Enter engine horsepower: ";
                                cin >> horsepower;
                                manager->addVehicle(new Car(make, model, year, Engine("Petrol", horsepower), doors));
                            } else if (type == "Bike") {
                                cout << "Enter bike type: ";
                                cin >> bikeType;
                                cout << "Enter engine horsepower: ";
                                cin >> horsepower;
                                manager->addVehicle(new Bike(make, model, year, Engine("Gasoline", horsepower), bikeType));
                            } else if (type == "Truck") {
                                cout << "Enter capacity (in tons): ";
                                cin >> capacity;
                                cout << "Enter engine horsepower: ";
                                cin >> horsepower;
                                manager->addVehicle(new Truck(make, model, year, Engine("Diesel", horsepower), capacity));
                            } else if (type == "Rickshaw") {
                                cout << "Enter driver name: ";
                                cin >> driverName;
                                cout << "Enter engine horsepower: ";
                                cin >> horsepower;
                                manager->addVehicle(new Rickshaw(make, model, year, Engine("Petrol", horsepower), driverName));
                            } else {
                                cout << "Invalid vehicle type." << endl;
                            }
                            break;
                        }
                        case 3: {
                            // Implement removing a vehicle if needed
                            string make, model;
                            cout << "Enter make of the vehicle to remove: ";
                            cin >> make;
                            cout << "Enter model of the vehicle to remove: ";
                            cin >> model;
                            manager->removeVehicle(make, model);
//                break;
                            break;
                        }
                        case 4: {
                            string make, model;
                            cout << "Enter make of the vehicle to check: ";
                            cin >> make;
                            cout << "Enter model of the vehicle to check: ";
                            cin >> model;
                            manager->isVehicleAvailable(make, model);
                            break;
                        }
                        case 5: {
                            manager->saveToJson("vehicles.json");
                            cout << "Vehicles saved to vehicles.json." << endl;
                            break;
                        }
                        case 9:
                            cout << "Exiting..." << endl;
                            break;
                        case 7: {
                            string make, model;
                            cout << "Enter make of the vehicle to search: ";
                            cin >> make;
                            cout << "Enter model of the vehicle to search: ";
                            cin >> model;
                            Vehicle* foundVehicle = manager->searchVehicle(make, model);
                            if (foundVehicle) {
                                cout << "Vehicle found:" << endl;
                                foundVehicle->display();
                            } else {
                                cout << "Vehicle not found." << endl;
                            }
                            break;
                        }
                        case 8: {
                            cout << "Available Vehicles:" << endl;
                            manager->displayAvailableVehicles();
                            break;
                        }
                        case 6: {
                            string make, model, newMake, newModel;
                            int newYear;
                            cout << "Enter make of the vehicle to update: ";
                            cin >> make;
                            cout << "Enter model of the vehicle to update: ";
                            cin >> model;
                            cout << "Enter new make: ";
                            cin >> newMake;
                            cout << "Enter new model: ";
                            cin >> newModel;
                            cout << "Enter new manufacturing year: ";
                            cin >> newYear;
                            manager->updateVehicleInfo(make, model, newMake, newModel, newYear);
                            break;
                        }
                        case 10: {
                            Engine e1("PETROL", 70);
                            Rickshaw r1("Honda", "2010", 2010, e1, "ALI");
                            cout << r1 << endl;
                        }

                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 10);

            }
            case 3: {
                try {
                    string filename = "drivers.json";
                    ManagerInfo mInfo("Khan", 40);
                    DriverManager manager = DriverManager::getInstance(filename, mInfo);
                    json drivers = manager.loadDriversFromFile();

                    int choice;
                    do {
                        cout << endl;
                        cout << "Menu:" << endl;
                        cout << "1. Add Truck Driver" << endl;
                        cout << "2. Add Car Driver" << endl;
                        cout << "3. Add Bike Driver" << endl;
                        cout << "4. Add Rickshaw Driver" << endl;
                        cout << "5. Display Drivers" << endl;
                        cout << "6. Display Available Drivers" << endl;
                        cout << "7. Book Driver" << endl;
                        cout << "8. Unbook the drivers" << endl;
                        cout << "9. Display Manager Information" << endl;
                        cout << "10.Display Truck Driver INFO (polymorphism)" << endl;
                        cout << "11. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;
                        if (!(choice >= 1 && choice <= 11))
                            throw "Choice should be in integer OR between 1 to 11";
                        switch (choice) {
                            case 1: {
                                string name, number, expirationDate, category;
                                int age;
                                cout << "Enter name: ";
                                cin >> name;
                                cout << "Enter age: ";
                                cin >> age;
                                cout << "Enter license number: ";
                                cin >> number;
                                cout << "Enter expiration date (YYYY-MM-DD): ";
                                cin >> expirationDate;
                                cout << "Enter category: ";
                                cin >> category;
                                CommercialLicense license(number, expirationDate, category);
                                drivers.push_back({
                                                          {"Name",    name},
                                                          {"Age",     age},
                                                          {"License", license.JsonW()}
                                                  });
                                manager.saveDriversToFile(drivers);
                                break;
                            }
                            case 2: {
                                string name, number, expirationDate, vehicleType;
                                int age;
                                cout << "Enter name: ";
                                cin >> name;
                                cout << "Enter age: ";
                                cin >> age;
                                cout << "Enter license number: ";
                                cin >> number;
                                cout << "Enter expiration date (YYYY-MM-DD): ";
                                cin >> expirationDate;
                                cout << "Enter vehicle type: ";
                                cin >> vehicleType;
                                NonCommercialLicense license(number, expirationDate, vehicleType);
                                drivers.push_back({
                                                          {"Name",    name},
                                                          {"Age",     age},
                                                          {"License", license.JsonWritting()}
                                                  });
                                manager.saveDriversToFile(drivers);
                                break;
                            }
                            case 3: {
                                string name, number, expirationDate, vehicleType;
                                int age;
                                cout << "Enter name: ";
                                cin >> name;
                                cout << "Enter age: ";
                                cin >> age;
                                cout << "Enter license number: ";
                                cin >> number;
                                cout << "Enter expiration date (YYYY-MM-DD): ";
                                cin >> expirationDate;
                                cout << "Enter vehicle type: ";
                                cin >> vehicleType;
                                NonCommercialLicense license(number, expirationDate, vehicleType);
                                json bikeDriver = {
                                        {"Name",    name},
                                        {"Age",     age},
                                        {"License", license.JsonWritting()}
                                };
                                drivers.push_back(bikeDriver);
                                manager.saveDriversToFile(drivers);
                                break;
                            }
                            case 4: {
                                string name, number, expirationDate, vehicleType, rickshawModel, rickshawNumber;
                                int age;
                                cout << "Enter name: ";
                                cin >> name;
                                cout << "Enter age: ";
                                cin >> age;
                                cout << "Enter license number: ";
                                cin >> number;
                                cout << "Enter expiration date (YYYY-MM-DD): ";
                                cin >> expirationDate;
                                cout << "Enter vehicle type: ";
                                cin >> vehicleType;
                                cout << "Enter rickshaw model: ";
                                cin >> rickshawModel;
                                cout << "Enter rickshaw number: ";
                                cin >> rickshawNumber;
                                NonCommercialLicense license(number, expirationDate, vehicleType);
                                json rickshawDriver = {
                                        {"Name",           name},
                                        {"Age",            age},
                                        {"License",        license.JsonWritting()},
                                        {"RickshawModel",  rickshawModel},
                                        {"RickshawNumber", rickshawNumber}
                                };
                                drivers.push_back(rickshawDriver);
                                manager.saveDriversToFile(drivers);
                                break;
                            }
                            case 5: {
                                manager.displayDriver();
                                break;
                            }
                            case 6: {
                                manager.displayAvailableDrivers();
                                break;
                            }
                            case 7: {
                                manager.displayAvailableDrivers();
                                string name;
                                cout << "Enter driver's name to book: ";
                                cin >> name;
                                manager.bookDriver(drivers, name);
                                manager.saveDriversToFile(drivers);
                                break;
                            }
                            case 8: {
                                cout << "Drivers which are booked are: " << endl;
                                manager.displayUnavailableDrivers();
                                string name;
                                cout << "Enter driver's name to book: ";
                                cin >> name;
                                manager.unbookDriver(drivers, name);
                                break;
                            }
                            case 9: {
                                cout << mInfo << endl;
                                break;
                            }
                            case 10: {
                                CommercialLicense commercialLicense("LEC2343", "12308", "ClassA");
                                TruckDriver<CommercialLicense> truckDriver("John", 30, &commercialLicense);
                                truckDriver.displayInfo();
                                break;
                            }
                            case 11: {
                                cout << "Exiting..." << endl;
                                return 0;
                            }
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    } while (choice != 11);
                }
                catch (const char *msg) {
                    cout << "Error " << msg << endl;
                    return 1;
                }
            }
            default:
                cout << "Invalid choice" << endl;
        }
    }while(select != 3);
    return 0;
}
