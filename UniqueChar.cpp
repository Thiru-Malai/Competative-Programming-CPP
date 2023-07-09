#include <bits/stdc++.h>
using namespace std;

char uniqueCharUsingMaps(string s1, string s2){
    unordered_map<char, int> m;
    for(int i = 0; i < (int)s1.size(); i++){
        m[s1[i]]++;
    }
    for(int i = 0; i < (int)s2.size(); i++){
        if(m.find(s2[i]) == m.end()){
            return s2[i];
        }
    }
    return 'a';
}


char uniqueCharEachOneFreq(string s1, string s2){
    int sum1 = 0, sum2 = 0;
    for(auto i: s1){
        sum1+=i;
    }
    for(auto i: s2){
        sum2+=i;
    }
    return char(abs(sum2-sum1));
}


int main(){
    string s1 = "abcd";
    string s2 = "abcde";
    cout<<uniqueCharUsingMaps(s1, s2)<<endl;
    cout<<uniqueCharEachOneFreq(s1, s2);
}