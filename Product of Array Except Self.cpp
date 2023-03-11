// Product of Array Except Self

// Source - LEETCODE

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

//  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//  You must write an algorithm that runs in O(n) time and without using the division operation.

//  Example 1:

//  Input: nums = [1,2,3,4]
//  Output: [24,12,8,6]
//  Example 2:

//  Input: nums = [-1,1,0,-3,3]
//  Output: [0,0,9,0,0]


vector<int> productExceptSelf(vector<int>& v) {
    int n = v.size();
    int count = 0, prod = 1;
    for(int i = 0; i < n; i++){
        if(v[i] == 0){
            count++;
        }
        if(count == 2){
            fill(v.begin(), v.end(), 0);
            return v;
        }
        if(v[i] != 0){
            prod*=v[i];
        }
    }
    if(count == 1){
        for(int i = 0; i < n; i++){
            if(v[i] != 0){
                v[i] = 0;
            }
            else{
                v[i] = prod;
            }
        }
    }
    else if(count == 0){
        for(int i = 0; i < n; i++){
                v[i] = prod / v[i];
        }
    }
    return v;
}
