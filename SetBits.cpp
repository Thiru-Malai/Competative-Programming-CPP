// CODING NINJAS
// https://www.codingninjas.com/studio/problems/set-bits_1164179?leftPanelTab=1

// Write an efficient program to count the number of 1s in the binary representation of an integer.
// Examples : 

// Input : n = 6
// Output : 2
// Binary representation of 6 is 110 and has 2 set bits

// Input : n = 13
// Output : 3
// Binary representation of 13 is 1101 and has 3 set bits


#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int countBits(int n){
    int count = 0;
    while(n != 0){
        int rem = n%2;
        if(rem == 1){
            count++;
        }
        n/=2;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}
