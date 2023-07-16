//CODING NINJAS
// Program to validate IP address
// https://www.codingninjas.com/studio/problems/program-to-validate-ip-address_981315

// You are given the text ‘IPAddress’. Your task is to check if the given text ‘IPAddress’ is a valid ‘IPv4’ or not.

// Sample Input 1:
// 4
// 123.111.12.k
// 122.0.330.0
// 1.1.1.250
// 1.0.0.0.1
// Sample Output 1:
// False
// False
// True
// False
// Explanation Of Sample Input 1:
// Test Case 1:
// Given text ‘IPAddress = 123.111.12.k’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed but it not satisfying the second condition that d must in a range of ‘0’ to ‘255’ but the value of ‘d’ is ‘k’.
// Hence return ‘False’.

// Test Case 2:
// Given text ‘IPAddress = 122.0.330.0’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed but it not satisfying the second condition that c must in a range of ‘0’ to ‘255’ but the value of ‘c’ is ‘330’ and it is out of range.
// Hence return ‘False’.

// Test Case 3:
// Given text ‘IPAddress = 1.1.1.250’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed as well as it satisfying the second condition that a,b,c, and d must in range of ‘0’ to ‘250’.
// Hence return ‘True’.

// Test Case 4:
// Given text ‘IPAddress = 1.0.0.0.1’, it is not satisfying the first condition for valid ‘IPv4’, that text ‘IPAddress’ must be in form of ‘a.b.c.d’ but given text is a form of ‘a.b.c.d.e’
// Hence return ‘False’.

#include <bits/stdc++.h> 
bool isValidIPv4(string ipAddress) {
    stringstream s(ipAddress);
    string word;
    int count = 0;
    while(!s.eof()){
        count++;
        if(count > 4){
            return false;
        }
        getline(s, word, '.');
        if(isalpha(word[0])){
            return false;
        }
        else if(isdigit(word[0])){
            int val = stoi(word);
            if(val > 255 || val < 0){
                return false;
            }
        }
    }
    if(count < 4){
        return false;
    }
    return true;
}