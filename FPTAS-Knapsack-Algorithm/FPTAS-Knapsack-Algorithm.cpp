// FPTAS-Knapsack-Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

std::vector<int> knapsackFPTAS(const std::vector<Item>& items, int capacity, double epsilon) {
    
    int maxValue = 0; //initialise the start value

    for (int i = 0; i < items.size(); i++) { //check each item
        if (items[i].weight <= capacity) { //ignore if the item cant fit
            if (items[i].value > maxValue) {
                maxValue = items[i].value; //update largest value
            }
        }
    }

    if (maxValue == 0) { //return nothing if no max value
        return {};
    }

    double K = epsilon * maxValue / items.size(); // scaling factor

    std::vector<int> scaledValues(items.size()); //scale values

    for (int i = 0; i < items.size(); i++) { //for each item
        scaledValues[i] = static_cast<int>( //use scaling factor so that the DP doesn't need to handle the full original values
            std::floor(items[i].value / K)//round down to the nearest integer
            );
    }



    return {};
}

int main() {
    std::cout << "FPTAS project is running!" << std::endl;
    return 0;
}