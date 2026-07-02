class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        grid_ = grid;
        m = grid_.size();
        int maxArea = 0;
        for (int row = 0; row < m; row++)
        {
            n = grid_[row].size();
            for (int col = 0; col < n; col++)
            {        
               if (grid_[row][col] == 1)
               {
                    int area = exploreIsland(row, col);
                    maxArea = max(maxArea, area);
               }
            }
        }        
        return maxArea;
    }

    int exploreIsland(int row, int col)
    {
        if (row < 0 || row >= m) { return 0; }
        if (col < 0 || col >= n) { return 0; }
        if (grid_[row][col] == 1)
        {
            grid_[row][col] = 0; 
            return 1 + exploreIsland(row+1, col) +
                        exploreIsland(row-1, col) +
                        exploreIsland(row, col+1) +
                        exploreIsland(row, col-1);
        }
        return 0;
    }

private:
    int m{0}, n{0};
    vector<vector<int>> grid_;
};
