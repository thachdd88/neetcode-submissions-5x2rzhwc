class Solution {
public:
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        record = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return modify(0, 0, word1, word2);
    }

    int modify(int i, int j, string &word1, string &word2) {
        if (i == m) { record[i][j] = n-j; } // insert w1
        else if (j == n) { record[i][j] = m-i; } // remove w1
        else if (record[i][j] == -1) {            
            if (word1[i] == word2[j]) { record[i][j] = modify(i+1, j+1, word1, word2); }
            else { record[i][j] = 1 + modify(i+1, j+1, word1, word2); } // replace
            record[i][j] = min(record[i][j], 1 + modify(i, j+1, word1, word2)); // insert
            record[i][j] = min(record[i][j], 1 + modify(i+1, j, word1, word2)); // remove
        }   
        return record[i][j];
    }    

private:
    int m, n;
    vector<vector<int>> record;
};
