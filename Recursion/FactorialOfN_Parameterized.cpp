//Parameterized Recursion

#include <bits/stdc++.h>
using namespace std;

int factorial(int n, int fact){
    if(n == 0){
        return fact;
    }
    return factorial(n-1, n*fact);
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n, 1);         // Parameterized Recursion
}