#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 4, b = 10;
    for (int i = a, j = b; i <= b; i++, j--)
    {
        if (i % 2 == 1)
            cout<<i<<" ";
        if (j % 2 == 0)
            cout<<j<<" "; 
    }
    // for(int i = a, j = b; i <= b && j >= a; i+=2, j-=2){
    //     if(i%2 != 0){
    //         cout<<i<<" ";
    //     }
    //     else{
    //         i = i+1;
    //         cout<<i<<" ";
    //     }
    //     if(j%2 == 0){
    //         cout<<j<<" ";
    //     }
    //     else{
    //         j = j-1;
    //         cout<<j<<" ";
    //     }
    // }
}