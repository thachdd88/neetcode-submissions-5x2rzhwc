class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int inf = 5000;
        vector<vector<int>> filled(n, vector<int>(n, inf));
        filled[0][0] = grid[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.push({grid[0][0], 0, 0});
        while (!q.empty())
        {
            auto [dist, row, col] = q.top();
            q.pop();
            if (dist > filled[row][col]) { continue; }
            if (row == n-1 && col == n-1) { break; }
            
            if (row-1 >= 0) { 
                int localMin = max(dist, grid[row-1][col]); 
                if (localMin < filled[row-1][col]) { filled[row-1][col] = localMin; q.push({localMin, row-1, col}); }
            }
            if (row+1 < n) {
                int localMin = max(dist, grid[row+1][col]); 
                if (localMin < filled[row+1][col]) { filled[row+1][col] = localMin; q.push({localMin, row+1, col}); }
            }
            if (col-1 >= 0) {
                int localMin = max(dist, grid[row][col-1]); 
                if (localMin < filled[row][col-1]) { filled[row][col-1] = localMin; q.push({localMin, row, col-1}); }
            }
            if (col+1 < n) {
                int localMin = max(dist, grid[row][col+1]); 
                if (localMin < filled[row][col+1]) { filled[row][col+1] = localMin; q.push({localMin, row, col+1}); }
            }
        }
        
        return filled[n-1][n-1];
    }
};
