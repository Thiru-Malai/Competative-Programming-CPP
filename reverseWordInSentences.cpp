#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "I am thirumalai. Hi Sir!";
    string word = "";
    string res = "";
    for(int i = s.size()-1; i >= 0 ; i--){
        if(s[i] != ' '){
            word+=s[i];
        }
        else{
            res+=word + ' ';
            word = "";
        }
    }
    cout<<res +  word;
}