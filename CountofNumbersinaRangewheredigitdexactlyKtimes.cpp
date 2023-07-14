// NON DP APPROACH
#include <bits/stdc++.h>
using namespace std;

int countNumbers(int l, int r, int d, int k){
    int count = 0, digit = 0;
    for(int i = l+1; i <= r; i++){
        int num = i;
        digit = 0;
        while(num != 0){
            int rem = num%10;
            if(rem == d){
                digit++;
            }
            num/=10;
        }
        if(digit == k){
            count++;
        }
    }
    return count;
}

int main(){
    int l, r, d, k;
    cin>>l>>r>>d>>k;
    cout<<countNumbers(l, r, d, k);
}