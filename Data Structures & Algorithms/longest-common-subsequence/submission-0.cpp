class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.length();
        n2 = text2.length();
        record = vector<vector<int>>(n1, vector<int>(n2, -1));
        return countComSub(0, text1, 0, text2);
    }

    int countComSub(int idx1, string &t1, int idx2, string &t2)
    {
        if (idx1 >= n1) { return 0;}
        if (idx2 >= n2) { return 0;}
        if (record[idx1][idx2] == -1)
        {
            if (t1[idx1] == t2[idx2])
            {
                record[idx1][idx2] = 1 + countComSub(idx1+1, t1, idx2+1, t2);
            }
            else 
            {
                record[idx1][idx2] = max(countComSub(idx1, t1, idx2+1, t2), 
                                    countComSub(idx1+1, t1, idx2, t2));
            }
        }
        return record[idx1][idx2];
    }

private:
    int n1{0}, n2{0};
    vector<vector<int>> record;
};
