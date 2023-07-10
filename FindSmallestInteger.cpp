#include <bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int> v){
    int res = 1;
    for(int i = 0; i < (int)v.size() && v[i] <= res; i++){
        res+=v[i];
    }
    return res;
}

int main(){
    vector<int> v = {1, 1, 3};
    cout<<findSmallestInteger(v);
}
