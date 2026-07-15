class Solution {
public:
#if 1
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> inTree(n, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        int answer = 0;
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [w, r, c] = pq.top(); pq.pop();
            if (inTree[r][c]) continue;         // stale entry, already in tree
            inTree[r][c] = true;
            answer = max(answer, w);            // bottleneck grows monotonically with tree

            if (r == n - 1 && c == n - 1) break;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !inTree[nr][nc]) {
                    pq.push({grid[nr][nc], nr, nc});   // raw elevation = edge weight into tree
                }
            }
        }
        return answer;
    }
#else
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
#endif
};
