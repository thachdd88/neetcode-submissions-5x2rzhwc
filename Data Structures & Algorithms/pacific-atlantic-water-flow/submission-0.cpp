class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) { return vector<vector<int>>(); }

        heights_ = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        printLand(heights_);

        // Water scan
        for (int i = 0; i < m; i++)
        {            
            scanWaterflow(pacific, i, 0, 1);
            scanWaterflow(atlantic, i, n-1, 2);
        }
        for (int i = 0; i < n; i++)
        {
            scanWaterflow(pacific, 0, i, 1);
            scanWaterflow(atlantic, m-1, i, 2);
        }
        // printLand(pacific);
        // printLand(atlantic);

        vector<vector<int>> res{};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] != 0 && atlantic[i][j] != 0)
                {
                    vector<int> point = {i, j};
                    res.emplace_back(point);
                }

        return res;
    }

    void scanWaterflow(vector<vector<int>> &land, int row, int col, int label)
    {
        land[row][col] = label;

        if (row-1 >= 0 && land[row-1][col] == 0 && heights_[row-1][col] >= heights_[row][col]) { scanWaterflow(land, row-1, col, label); }
        if (row+1 < heights_.size() && land[row+1][col] == 0 && heights_[row+1][col] >= heights_[row][col]) { scanWaterflow(land, row+1, col, label); }

        if (col-1 >= 0 && land[row][col-1] == 0 && heights_[row][col-1] >= heights_[row][col]) { scanWaterflow(land, row, col-1, label); }
        if (col+1 < heights_[row].size() && land[row][col+1] == 0 && heights_[row][col+1] >= heights_[row][col]) { scanWaterflow(land, row, col+1, label); }
    }

    void printLand(vector<vector<int>> &land)
    {
        printf("Land:\n");
        for (auto &row : land)
        {
            for (auto &cell : row) { printf("%d\t", cell); }
            printf("\n");
        }
    }

private:
    vector<vector<int>> heights_;
};
