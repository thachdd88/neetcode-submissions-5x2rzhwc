class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        preSum_ = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int colPrefix = 0;
            for (int j = 0; j < n; j++) {
                colPrefix += matrix[i][j];
                if (i > 0) {
                    preSum_[i][j] = preSum_[i-1][j] + colPrefix;
                }
                else { preSum_[i][j] = colPrefix; }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int uperPart = (row1 > 0) ? preSum_[row1-1][col2] : 0;
        int leftPart = (col1 > 0) ? preSum_[row2][col1-1] : 0;
        int complement = (row1 > 0 && col1 > 0) ? preSum_[row1-1][col1-1] : 0;
        return preSum_[row2][col2] - uperPart - leftPart + complement;
    }

private:
    int m, n;
    vector<vector<int>> preSum_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */