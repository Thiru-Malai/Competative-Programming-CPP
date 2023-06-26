// Maximum Chocolates
// Input:  [9, 10, 3, 4], k = 2
// Output: 19
// Explanation:
// 1. Max: 10 sum+= 10 (max/2) = 5
//    Array becomes [9, 5, 3, 4]
// 2. Max: 9 sum+= 9 (max/2) = 4
// Since k == 2, return sum

#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(vector<int> arr, int k){
    int MOD = 1000000007;
    int n = arr.size()-1;

    int ans = 0;
    priority_queue<int> pq;
    for(int i = 0; i <= n; i++){
        pq.push(arr[i]);
    }

    while(k--){
        int max = pq.top();
        pq.pop();
        ans+=(max) % MOD;
        pq.push(max/2);
    }
    return ans;
}

int main(){
    int k;
    cin>>k;
    vector<int> arr = {9, 20, 3, 4};
    cout<<maximumChocolates(arr, k);
}
