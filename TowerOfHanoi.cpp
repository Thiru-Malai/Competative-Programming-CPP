#include <bits/stdc++.h>
using namespace std;
void TOH(int n, int source, int dest, int aux , vector<vector<int>> &ans){
    if(n == 0){
        return;
    }
    TOH(n-1, source, aux, dest, ans);
    ans.push_back({source, dest});
    TOH(n-1, aux, dest, source, ans);
}

int main(){
    vector<vector<int>> ans;
    int n = 3;
    TOH(n, 1, 2, 3, ans);
    for(int i = 0; i < (int)ans.size(); i++){
        for(int j = 0; j < (int)ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }   
}