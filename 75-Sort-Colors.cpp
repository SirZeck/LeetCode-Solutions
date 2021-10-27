// Problem Link: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        multiset<int> s(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.begin();
            nums[i] = *it;
            s.erase(s.begin());
        }
    }
};