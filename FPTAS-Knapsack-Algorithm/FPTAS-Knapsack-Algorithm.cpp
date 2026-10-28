// FPTAS-Knapsack-Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

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

    int totalScaledValue = 0; //initialise total scaled value

    for (int i = 0; i < items.size(); i++) { 
        if (items[i].weight <= capacity) { //calculate the largest possible sum of scaled values if every item is included individually
            totalScaledValue += scaledValues[i];
        }
    }

    std::vector<int> dp(totalScaledValue + 1, INT_MAX); //dp to store minimum weight needed for each scaled value where INT_MAX means the value is unreachable
    dp[0] = 0; //set DP to zero because weight 0 if none selected

    for (int i = 0; i < items.size(); i++) { //process each item
        if (items[i].weight > capacity) {
            continue;
        }

        for (int v = totalScaledValue; v >= scaledValues[i]; v--) { //loop backwards to prevent the same item being used in the same iteration
            if (dp[v - scaledValues[i]] != INT_MAX) {
                int newWeight = dp[v - scaledValues[i]] + items[i].weight; //calculate new weight

                if (newWeight < dp[v]) {  //check if new weight is new best
                    dp[v] = newWeight; //update dp
                }
            }
        }
    }

    return {};
}

int main() {
    std::cout << "FPTAS project is running!" << std::endl;
    return 0;
}