class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        if (grid.empty() || grid[0].empty()) { return; }
        m = grid.size();
        n = grid[0].size();
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
                if (grid[row][col] == 0) 
                { 
                    updateDist(grid, row+1, col, 1);
                    updateDist(grid, row-1, col, 1);
                    updateDist(grid, row, col+1, 1);
                    updateDist(grid, row, col-1, 1);
                }
        }    
    }
    void updateDist(vector<vector<int>>& grid, int row, int col, int dist)
    {
        if (row < 0 || row >= m) { return; }
        if (col < 0 || col >= n) { return; }
        if ((grid[row][col] > 0) && (grid[row][col] > dist))
        {
            grid[row][col] = dist;
            updateDist(grid, row+1, col, dist+1);
            updateDist(grid, row-1, col, dist+1);
            updateDist(grid, row, col+1, dist+1);
            updateDist(grid, row, col-1, dist+1);
        }
    }
private:
    int m{0}, n{0};
};
