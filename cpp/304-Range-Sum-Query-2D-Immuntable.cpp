// Problem Link: https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
private:
    int rows, cols;
    vector<vector<int>> sum;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = (rows > 0 ? matrix[0].size() : 0);
        sum = vector<vector<int>> (rows + 1, vector<int> (cols + 1));
        
        for (int row = 1; row <= rows; row++)
            for (int col = 1; col <= cols; col++) {
                sum[row][col] = matrix[row - 1][col - 1] + sum[row-1][col] + sum[row][col-1] - sum[row-1][col-1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};