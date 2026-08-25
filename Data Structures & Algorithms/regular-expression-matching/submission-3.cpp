class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> valid(m+1, vector<bool>(n+1, false)); 
        valid[0][0] = true;
        for (int j = 1; j <= n; j++)
            if (p[j-1] == '*') { valid[0][j] = valid[0][j-2]; }

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                if (p[j-1] == '.' || p[j-1] == s[i-1]) { valid[i][j] = valid[i-1][j-1]; }
                else if (p[j-1] == '*') {
                    valid[i][j] = valid[i][j-2]; // zero match with the preceding key
                    if (p[j-2] == '.' || p[j-2] == s[i-1]) 
                        valid[i][j] = valid[i][j] || valid[i-1][j];
                }
                else { valid[i][j] = false; }
            }            
        }
      
        return valid[m][n];
    }
};
