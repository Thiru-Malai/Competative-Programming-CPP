#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    int maxLength = INT_MIN;
    int length = 0;
    unordered_map<char, int> m;
    unordered_map<char, int>::iterator it;

    for (int i = 0; i < (int)input.size(); i++)
    {
        if (m.find(input[i]) != m.end() && m[input[i]] != 0)
        {
            if (length > maxLength)
            {
                maxLength = length;
            }
            i = i-length+1;;
            length = 0;
            for (it = m.begin(); it != m.end(); it++)
            {
                it->second = 0;
            }
            cout<<endl<<endl;
        }
        if (m[input[i]] == 0)
        {
            prev = i;
            length++;
            m[input[i]]++;
            cout<<input[i];
        }
        if ((m.find(input[i]) == m.end()))
        {
            m.insert(make_pair(input[i], 1));
            length++;
            cout<<input[i];
        }
    }
    if(maxLength == INT_MIN){
        return length;
    }
    return maxLength;
}

int main()
{
    cout << uniqueSubstrings("kfsmygpcwzvueiaqxjnhdoblrt");
    return 0;
}
