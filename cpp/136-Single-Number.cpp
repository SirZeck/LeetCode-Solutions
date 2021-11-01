// Problem Link: https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
//         multiset<int> m(nums.begin(), nums.end());
        
//         int ans = -1;
//         for (int i = 0; i < nums.size(); i++) {
//             if (m.count(nums[i]) == 1) {
//                 ans = nums[i];
//                 break;
//             }
//         }
//         return ans;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans ^= nums[i];
        
        return ans;
    }
};