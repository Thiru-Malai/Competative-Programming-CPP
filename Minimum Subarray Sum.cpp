#include <bits/stdc++.h> 
using namespace std;

int minSubarraySum(int arr[], int n, int k) 
{
    int sum = 0, minSum = INT_MAX;
    for(int i = 0; i < k; i++){
        sum+=arr[i];
    }
    minSum = sum;
    sum = minSum;
    for(int i = 1; i < n-k + 1; i++){
        sum-=arr[i-1];
        sum+=arr[i+k-1];
        if(minSum > sum){
            minSum = sum;
        }
    }
    return minSum;
}

int main(){
    int arr[] = {10, 4, 2, 5, 6, 3, 8, 1};
    int k = 3;
    cout<<minSubarraySum(arr, 8, k);
}