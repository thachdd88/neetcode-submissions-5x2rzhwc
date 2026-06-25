class Solution {
public:
    vector<string> res;        
    string cur;
    vector<string> generateParenthesis(int n) 
    {
        backtrace(n, 0, 0);
        return res;
    }
    void backtrace(int n, int open, int close) 
    {
        if (cur.length() == 2*n) { res.push_back(cur); return; }

        if (open < n)
        {
            cur.push_back('(');
            backtrace(n, open+1, close);
            cur.pop_back();
        }        
        
        if (close < open)
        {
            cur.push_back(')');
            backtrace(n, open, close+1);
            cur.pop_back();
        }
    }
};
