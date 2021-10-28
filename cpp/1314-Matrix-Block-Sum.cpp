// Problem Link: https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dp(rows + 1, vector<int> (cols + 1));
        
        dp[0][0] = mat[0][0];
        
        for (int row = 1; row < rows; row++)
            dp[row][0] = dp[row-1][0] + mat[row][0];
        
        for (int col = 1; col < cols; col++)
            dp[0][col] = dp[0][col-1] + mat[0][col];
        
        for (int row = 1; row < rows; row++)
            for (int col = 1; col < cols; col++)
                dp[row][col] = dp[row-1][col] + dp[row][col-1] - 
                dp[row-1][col-1] + mat[row][col];
        
        vector<vector<int>> ans(rows, vector<int> (cols));
        
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++) {
                ans[row][col] = dp[min(row+k, rows-1)][min(col+k, cols-1)] - (
                    (col-k-1) >= 0 ? dp[min(row+k, rows-1)][col-k-1] : 0) - 
                    ((row-k-1) >= 0 ? dp[row-k-1][min(cols-1, col+k)] : 0) +
                    (((col-k-1) >= 0 && (row-k-1) >= 0) ? dp[row-k-1][col-k-1] : 0);
            }
        
        return ans;
    }
};