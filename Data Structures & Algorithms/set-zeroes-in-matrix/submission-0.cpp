class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {        
        set<int> col, row;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) { row.insert(i); col.insert(j); }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (row.find(i) != row.end()) { matrix[i] = vector<int>(matrix[i].size(), 0); }
            else {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if (col.find(j) != col.end()) { matrix[i][j] = 0; }
                }
            }
        }
    }
};
