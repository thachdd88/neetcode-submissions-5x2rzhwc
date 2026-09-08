class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {        
        bool topHasZero{false}, leftHasZero{false};
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) { if (matrix[i][0] == 0) { leftHasZero = true; break; }}
        for (int i = 0; i < n; i++) { if (matrix[0][i] == 0) { topHasZero = true; break; }}

        // marking excluding top & left
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // update matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) { matrix[i][j] = 0; }
            }
        }
        if (topHasZero) {
            for (int j = 0; j < n; j++) { matrix[0][j] = 0; }
        }
        if (leftHasZero) {
            for (int i = 0; i < m; i++) { matrix[i][0] = 0; }
        }
    }
};
