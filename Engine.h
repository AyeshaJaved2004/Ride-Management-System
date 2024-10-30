//
// Created by GLOBAL LAPTOP BAZAR on 5/9/2024.
//

#ifndef UNTITLED_ENGINE_H
#define UNTITLED_ENGINE_H
#include <string>
#include "nlohmann/json.hpp"
#include<iostream>
#include<string>
using namespace std;
using json = nlohmann::json;

class Engine {
private:
    string type;
    int horsepower;

public:
    Engine(string _type, int _horsepower);

    json toJson() ;
};
#endif //UNTITLED_ENGINE_H
