// Given a sentence containing many words you have to reverse all the alphanumeric characters.
// Input:  my ^&na$me@#$ is123 Mike
// Output: ek ^&iM$32@#$ 1siem anym

#include <bits/stdc++.h>
using namespace std;

int main(){
    string word, s;
    getline(cin, s);
    int i = 0, j = (int)s.size()-1;
    while(i <= j){
        if(!isalnum(s[i])){
            i++;
            continue;
        }
        if(!isalnum(s[j])){
            j--;
            continue;
        }
        if(isalnum(s[i]) && isalnum(s[j])){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    cout<<s;
}