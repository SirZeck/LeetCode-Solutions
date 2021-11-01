// Problem Link: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // TC: O(nlogn) SC: O(1)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() / 2];
        
        //using Moore's voting algo TC/SC: O(n)/O(1)
        int majorityIndex = 0;
        for (int count = 0, i = 0; i < nums.size(); i++) {
            if (nums[majorityIndex] == nums[i] ? count++ : count--);
            if (count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }
        
        return nums[majorityIndex];
    }
};