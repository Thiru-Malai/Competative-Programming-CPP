#include <bits/stdc++.h>
using namespace std;

float Calculate(float P, int N, float R){
    int Year = 1;
    float sum = 1;
    sum = sum * (1 + P * ++N * R);
    Year =(int)Year + sum;
    return Year;
}

int main(){
    float amount;
    float Calculate(float P = 5.0, int N = 2, float = 2.0);
    amount = Calculate();
    cout<<amount;
}