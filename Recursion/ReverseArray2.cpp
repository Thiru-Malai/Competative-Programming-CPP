// One Pointer Method

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v, int i){
    if(i >= (int)v.size()/2){
        return;
    }
    swap(v[i], v[v.size()-i-1]);
    reverse(v, i+1);
}

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    reverse(v, 0);         // Functional Recursion
    for(auto i: v){
        cout<<i<<" ";
    }
}
