// Given a sentence containing many words you have to reverse all the alphanumeric characters in each and every word of the sentence
// Input:  "my ^&na$me@#$ is123 Mike"
// Output: "ym ^&an$em@#$ 321si ekiM"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word, s;
    while (cin >> word)
    {
        if (word == "end")
        {
            break;
        }
        int i = 0, j = (int)word.size() - 1;
        while (i <= j)
        {
            if (!isalnum(word[i]))
            {
                i++;
                continue;
            }
            if (!isalnum(word[j]))
            {
                j--;
                continue;
            }
            if (isalnum(word[i]) && isalnum(word[j]))
            {
                swap(word[i], word[j]);
                i++;
                j--;
            }
        }
        s+=word + " ";
    }
    cout << s;
}