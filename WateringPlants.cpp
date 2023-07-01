// Watering Plants
// You want to water n plants in your garden with a watering can. The plants are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith plant is located at x = i. There is a river at x = -1 that you can refill your watering can at.

// Each plant needs a specific amount of water. You will water the plants in the following way:

// Water the plants in order from left to right.
// After watering the current plant, if you do not have enough water to completely water the next plant, return to the river to fully refill the watering can.
// You cannot refill the watering can early.
// You are initially at the river (i.e., x = -1). It takes one step to move one unit on the x-axis.

// Given a 0-indexed integer array plants of n integers, where plants[i] is the amount of water the ith plant needs, and an integer capacity representing the watering can capacity, return the number of steps needed to water all the plants.

// Input: plants = [2,2,3,3], capacity = 5
// Output: 14
// Explanation: Start at the river with a full watering can:
// - Walk to plant 0 (1 step) and water it. Watering can has 3 units of water.
// - Walk to plant 1 (1 step) and water it. Watering can has 1 unit of water.
// - Since you cannot completely water plant 2, walk back to the river to refill (2 steps).
// - Walk to plant 2 (3 steps) and water it. Watering can has 2 units of water.
// - Since you cannot completely water plant 3, walk back to the river to refill (3 steps).
// - Walk to plant 3 (4 steps) and water it.
// Steps needed = 1 + 1 + 2 + 3 + 3 + 4 = 14.

#include <bits/stdc++.h>
using namespace std;
int totalSteps(int n, int k, vector<int> &flowers) {
    int steps = 0;
    int size = k;
    for(int i = 0; i < n; i++){
        steps++;
        if(flowers[i] <= k){
            k-=flowers[i];
        }
        else if(flowers[i] > k){
            steps += ((i) * 2);
            k = size;
            k-=flowers[i];
        }
    }
    return steps;
}

int main(){
    vector<int> v = {2, 2, 3, 3};
    int k = 5;
    cout<<totalSteps((int)v.size(), k, v);
}
