// CODING NINJAS
// Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

// Note: We can either take the item as a whole or break it into smaller units.

// Example:

// Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

// Output: 240.00

// Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00

#include <bits/stdc++.h> 
using namespace std;
bool comparator(pair<int, int> p1, pair<int, int> p2){
    double value1 = (1.0)*p1.second/p1.first;        // Value Weight Ratio
    double value2 = (1.0)*p2.second/p2.first;        // Value Weight Ratio
    return value1 > value2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comparator);
    double maxValue = 0.0;
    for(int i = 0; i < n; i++){
        double value = items[i].second;         // Value
        double weight = items[i].first;         // Weight
        if(w-weight >= 0){
            maxValue+=value;
            w-=weight;
        }
        else{
            double ratio = (1.0)*value/weight;
            maxValue+=(ratio*w);
            w-=w;
        }
    }  
    return maxValue;
}

int main() {
   int n = 3, weight = 50;
   vector<pair<int, int>> items = { {100,20},{60,10},{120,30} };
   double ans = maximumValue(items, n, weight);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}