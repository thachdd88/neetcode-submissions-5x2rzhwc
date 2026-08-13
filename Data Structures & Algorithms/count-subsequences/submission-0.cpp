class Solution {
public:
    int numDistinct(string s, string t) 
    {
        m = s.length();
        n = t.length();
        record = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return search(0, 0, s, t);
    }
    int search(int i, int j, string &s, string &t) {
        if (j >= n) { record[i][j] = 1; }
        else if (i >= m) { record[i][j] = 0; }
        else if (record[i][j] == -1) {
            record[i][j] = 0;
            if (s[i] == t[j]) { record[i][j] = search(i+1, j+1, s, t); }
            record[i][j] += search(i+1, j, s, t);
        }
        return record[i][j];
    }    

private:
    int m, n;
    vector<vector<int>> record;
};
