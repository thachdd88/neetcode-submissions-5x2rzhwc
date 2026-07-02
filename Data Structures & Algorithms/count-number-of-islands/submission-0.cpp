class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {        
        grid_ = grid;
        int islands{0};
        m = grid.size();
        for (int row = 0; row < grid_.size(); row++)
        {
            n = grid_[row].size();
            for (int col = 0; col < grid_[row].size(); col++)
                if (grid_[row][col] == '1')
                {
                    islands++;
                    shrinkIsland(row, col);
                }
        }
        return islands;
    }
    void shrinkIsland(int row, int col)
    {
        if (row < 0 || row >= m) { return; }
        if (col < 0 || col >= n) { return; }
        if (grid_[row][col] == '1')
        {
            grid_[row][col] = '0';
            shrinkIsland(row+1, col);
            shrinkIsland(row-1, col);
            shrinkIsland(row, col+1);
            shrinkIsland(row, col-1);
        }
    }

private:
    int m{0}, n{0};
    vector<vector<char>> grid_;
};
