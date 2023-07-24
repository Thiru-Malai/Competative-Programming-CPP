// Coding Ninjas
// https://www.codingninjas.com/studio/problems/meta-strings_1089556
// Given two strings, the task is to check whether these strings are meta strings or not. Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.

// Examples: 

// Input : str1 = "geeks" 
//         str2 = "keegs"
// Output : Yes
// By just swapping 'k' and 'g' in any of string, 
// both will become same.

// Input : str1 = "rsting"
//         str2 = "string
// Output : No


#include <bits/stdc++.h> 
bool checkMeta(string &str1, string &str2)
{
    if(str1.size() != str2.size()){
        return false;
    }
    if(str1 == str2){
        return false;
    }
    int flag = 0;
    int index = 0;
    char c;
    for(int i = 0; i < str1.size(); i++){
        if(str1[i] != str2[i] && flag == 0){
            c = str1[i];
            flag = 1;
            index = i;
        }
        else if(flag == 1 && str1[i] != str2[i]){
            char temp = str1[i];
            str1[i] = c;
            str1[index] = temp;
            break;
        }
    }
    if(str1 == str2){
        return true;
    }
    return false;
}
