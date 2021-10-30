// Problem Link: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                int a = (i && j) ? A[i - 1][j - 1] : 0;
                int b = (i) ? A[i - 1][j] : 0;
                int c = (j) ? A[i][j - 1] : 0;
                
                A[i][j] = (A[i][j] > '0' ? min({a, b, c}) + 1 : 0);
                
                res = max(res, A[i][j] * A[i][j]);
            }
        }
        
        return res;
    }
};