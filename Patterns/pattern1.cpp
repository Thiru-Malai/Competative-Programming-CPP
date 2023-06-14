// Pattern 1
// input n = 3

// 00000
// 10001
// 21012
// 32123

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int line = n * 2 - 1;
    int k = line;
    for (int i = 0; i < line - 1; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        for (int j = i; j < k; j++)
        {
            cout << 0 << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            if(line - 2 == i && j == 1){
                continue;
            }
            cout << j << " ";   
        }
        k--;
        cout << endl;
    }
}
