// Problem Link: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int rot(vector<vector<int>>&grid, int i, int j, int dist) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != 1) return 0;
        
        grid[i][j] = dist + 3;
        return 1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int dist = 0; int fresh = 0;
        for (auto i = 0; i < grid.size(); ++i)
            fresh += count_if(begin(grid[i]), end(grid[i]), [](int j) {return j == 1;});
        
        for (auto old_fresh = fresh; fresh > 0; ++dist) {
            for (auto i = 0; i < grid.size(); ++i)
                for (auto j = 0; j < grid[i].size(); ++j)
                    if (grid[i][j] == dist + 2)
                        fresh -= rot(grid, i + 1, j, dist) + rot(grid, i - 1, j, dist) + rot(grid, i, j + 1, dist) + rot(grid, i, j - 1, dist);
                    
            if (fresh == exchange(old_fresh, fresh)) return -1;
        }
        
        return dist;
    }
};