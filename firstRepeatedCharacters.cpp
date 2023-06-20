// Find the first repeated character in a string
// Input: ch = “geeksforgeeks”
// Output: e
// e is the first element that repeats

// Input: str = “hello geeks”
// Output: l
// l is the first element that repeats

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[26] = { 0 };
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        char c = tolower(s[i]);
        int j = int(c) - 95;
        if (arr[j] == 0)
        {
            arr[j]++;
        }
        else
        {
            cout << s[i];
            break;
        }
    }
}
