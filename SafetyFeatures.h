//
// Created by GLOBAL LAPTOP BAZAR on 5/10/2024.
//

#ifndef UNTITLED_SAFETYFEATURES_H
#define UNTITLED_SAFETYFEATURES_H
#include <iostream>
#include <string>
#include<iostream>
#include<string>
using namespace std;
class SafetyFeatures{
public:
SafetyFeatures(bool abs, int airbags) : abs(abs), airbags(airbags) {}

    SafetyFeatures() {}

    bool hasABS()  { return abs; }
int getAirbags()  { return airbags; }
private:
bool abs;
int airbags;
};
#endif //UNTITLED_SAFETYFEATURES_H
