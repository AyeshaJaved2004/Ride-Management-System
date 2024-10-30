#include "Engine.h"
#include<iostream>
#include<string>
using namespace std;
Engine::Engine(string _type, int _horsepower) : type(_type), horsepower(_horsepower) {}

json Engine::toJson()  {
    return {
            {"type", type},
            {"horsepower", horsepower}
    };
}