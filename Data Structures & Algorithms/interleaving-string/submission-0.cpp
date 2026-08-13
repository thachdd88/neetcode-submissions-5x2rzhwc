class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();        
        n = s2.length();
        memo = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        if (m+n != s3.length()) { return false; }
        return check(0, 0, s1, s2, s3);
    }

    bool check(int i, int j, string &s1, string &s2, string &s3)
    {
        bool found{false};
        if (i+j == s3.length()) { found = true; }
        else if (memo[i][j] != -1) { found = (memo[i][j])? true : false; }
        else {
            if (!found && i < m && s1[i] == s3[i+j]) { found = check(i+1, j, s1, s2, s3); }
            if (!found && j < n && s2[j] == s3[i+j]) { found = check(i, j+1, s1, s2, s3); }
        }
        memo[i][j] = found? 1 : 0;
        return found;
    }

private:
    int m, n;
    vector<vector<int>> memo;
};
