#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v, int l, int r){
    if(l >= r){
        return;
    }
    swap(v[l], v[r]);
    reverse(v, l+1, r-1);
}

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    int l = 0, r = v.size()-1;
    reverse(v, l, r);         // Functional Recursion
    for(auto i: v){
        cout<<i<<" ";
    }
}
