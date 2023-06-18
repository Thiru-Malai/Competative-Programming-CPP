#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n, temp;
    cin>>n;
    int array[n];
    for(int i = 0; i < n; i++){
        cin>>array[i];
    }
    for(int i = 0; i < n-1; i++){
        int num = array[i];
        for(int j = i+1; j < n; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for(auto i : array){
        cout<<i<<" ";
    }
}