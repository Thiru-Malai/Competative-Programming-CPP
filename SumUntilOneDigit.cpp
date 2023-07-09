// Write a Program to check if any number is a magic number or not. A number is said to be a magic number if after doing sum of digits in each step and inturn doing sum of digits of that sum, the ultimate result (when there is only one digit left) is 1.
// Example, consider the number:

// Step 1: 163 => 1+6+3 = 10
// Step 2: 10 => 1+0 = 1 => Hence 163 is a magic number

#include <bits/stdc++.h>
using namespace std;

int findSum(int n){
    int sum = 0;
    while(n != 0){
        int rem = n%10;
        sum+=rem;
        n/=10;
        if(n <= 0 && sum > 9){
            n = sum;
            sum = 0;
        }
    }
    return sum;
}

int main(){
    int n = 100;
    if(findSum(n) == 1){
        cout<<"Magic Number";
    }
    else{
        cout<<"Not A Magic Number";
    }
}