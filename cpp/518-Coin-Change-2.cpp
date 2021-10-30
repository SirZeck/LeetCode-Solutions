// Problem Link: https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5005] = {1};
        
        for (int coin : coins) {
            for (int x = coin; x <= amount; x++)
                dp[x] += dp[x - coin];
        }
        
        return dp[amount];
    }
};