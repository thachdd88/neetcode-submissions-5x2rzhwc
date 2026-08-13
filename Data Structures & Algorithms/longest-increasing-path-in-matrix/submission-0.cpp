class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int longest{0};
        m = matrix.size();
        n = matrix[0].size();        
        record = vector<vector<int>>(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                longest = max(longest, search(i, j, matrix)); 
            }
        }
        return longest;
    }
    int search(int i, int j, vector<vector<int>> &matrix)
    {
        if (record[i][j] == -1)
        {
            record[i][j] = 0;
            if (i > 0 && matrix[i-1][j] > matrix[i][j]) { record[i][j] = max(record[i][j], search(i-1, j, matrix)); }
            if (i < m-1 && matrix[i+1][j] > matrix[i][j]) { record[i][j] = max(record[i][j], search(i+1, j, matrix)); }

            if (j > 0 && matrix[i][j-1] > matrix[i][j]) { record[i][j] = max(record[i][j], search(i, j-1, matrix)); }
            if (j < n-1 && matrix[i][j+1] > matrix[i][j]) { record[i][j] = max(record[i][j], search(i, j+1, matrix)); }

            record[i][j]++;
        }
        return record[i][j]; 
    }
private:
    int m, n;
    vector<vector<int>> record;
};
