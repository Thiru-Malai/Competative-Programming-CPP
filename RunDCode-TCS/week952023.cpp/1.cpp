#include <bits/stdc++.h>
using namespace std;

struct MyData{
    public:
    int addition(int a, int b = 10){
        return (a*=b+2);
    }
    float addition(int a, float b);
};

int main(){
    string s = "";
    float z = 5;
    cout<<(int)++z;
    MyData data;
    cout<<data.addition(1)<<" ";
    cout<<data.addition(3, 4);
    return 0;
}