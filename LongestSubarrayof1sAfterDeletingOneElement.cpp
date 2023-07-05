// LEETCODE
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//1493. Longest Subarray of 1's After Deleting One Element
// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.


class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int size = 0, sum = 0, len = arr.size();
        vector<int> resSums;
        for(int i = 0; i < len; i++){
            if(arr[i] == 0){
                resSums.push_back(sum);
                sum = 0;
            }
            else{
                sum+=arr[i];
            }
        }
        resSums.push_back(sum);
        for(auto i: resSums){
            cout<<i<<" ";
        }
        int maxSize = 0;
        int resSumsSize = resSums.size()-1;
        for(int i = 0; i < resSumsSize; i++){
            size = resSums[i] + resSums[i+1];
            if(size > maxSize){
                maxSize = size;
            }
        }
        if(resSumsSize == 0){
            return len-1;
        }
        return maxSize;
    }
};