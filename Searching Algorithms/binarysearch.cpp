#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                return nums[mid];
            }
            else if(nums[mid] < target){
                high = mid+1;
            }
            else if(nums[mid] >= target){
                low = mid;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout<<"Started";
    vector<int> v = {4,5,6,7,0,1,2};
    cout<<s.search(v, 0);
}