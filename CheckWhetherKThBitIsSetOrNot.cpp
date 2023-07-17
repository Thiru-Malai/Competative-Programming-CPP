// CODING NINJAS
// https://www.codingninjas.com/studio/problems/check-whether-k-th-bit-is-set-or-not_5026446
// Check whether K-th bit is set or not
// Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.

// Input: ‘N’ = 5, ‘K’ = 1

// Output: YES

// 5 in binary can be written as 101 and as we can see a first bit from the right of 5 is set so the answer is 'YES'.

// Sample Input 1 :
// 3 2
// Sample Output 1 :
// YES
// Explanation Of Sample Input 1 :
// 3 in binary can be represented as 11 and 2 bit from right is set there, So answer is 'YES'.

// Sample Input 2 :
// 128 7
// Sample Output 2 :
// NO


#include <bits/stdc++.h>
bool isKthBitSet(int n, int k)
{
    string binary = bitset<32>(n).to_string();
    reverse(binary.begin(), binary.end());
    // cout<<binary[k-1];
    if(binary[k-1] == '1'){
        return true;
    }
    return false;
}
