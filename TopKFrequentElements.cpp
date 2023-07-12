// LEETCODE
// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/description/

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        multimap<int, int> count;
        map<int, int>::reverse_iterator itr;
        map<int, int>::iterator it;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(it = m.begin(); it != m.end(); it++){
            count.insert(make_pair(it->second, it->first));
        }
        for(itr = count.rbegin(); itr != count.rend(); itr++){
            res.push_back(itr->second);
            if(--k == 0){
                break;
            }
        }
        return res;
    }
};
