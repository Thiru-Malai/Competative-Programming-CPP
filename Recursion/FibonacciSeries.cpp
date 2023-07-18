#include <bits/stdc++.h>
using namespace std;

int fibonacciOfN(int n){
    if(n <= 1){
        return n;
    }
    return fibonacciOfN(n-1) + fibonacciOfN(n-2);
}

int main(){
    int n;
    n = 5;
    cout<<fibonacciOfN(n);
}