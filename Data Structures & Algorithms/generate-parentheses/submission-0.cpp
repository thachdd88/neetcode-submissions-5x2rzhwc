class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        
        string cur;
        backtrace(n, 0, 0, cur, res);

        return res;
    }
    void backtrace(int n, int open, int close, string &cur, vector<string> &res) 
    {
        if (cur.length() == 2*n) { res.push_back(cur); return; }

        if (open < n)
        {
            cur.push_back('(');
            backtrace(n, open+1, close, cur, res);
            cur.pop_back();
        }        
        
        if (close < open)
        {
            cur.push_back(')');
            backtrace(n, open, close+1, cur, res);
            cur.pop_back();
        }
    }
};
