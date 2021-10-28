// Problem Link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1, back = nums.size() - 1;
            
            while (front < back) {
                int sum = nums[front] + nums[back];
                
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    res.push_back(triplet);
                    
                    //processing duplicates of number 2
                    //incrementing front pointer to next number
                    while (front < back && nums[front] == triplet[1]) front++;
                    
                    //processing duplicates of number 3
                    //decreamenting back pointer to previous number
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }
            
            //processing duplicates of number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        
        return res;
    }
};

/*the key idea is the same as the TwoSum problem. When we fix the 1st number, the 2nd and 3rd number can be found following the same reasoning as TwoSum.

The only difference is that, the TwoSum problem of LEETCODE has a unique solution. However, in ThreeSum, we have multiple duplicate solutions that can be found. Most of the OLE errors happened here because you could've ended up with a solution with so many duplicates.*/