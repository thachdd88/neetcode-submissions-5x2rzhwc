class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.length();
        vector<int> memo(n, -1);
        function<int(int)> fCnt = [&](int idx) -> int
        {
            if (idx == n) { return 1; }
            if (s[idx] == '0') { return 0; }
            if (memo[idx] != -1) { return memo[idx]; }
            int cnt = fCnt(idx+1);
            if (idx+1 < n)
            {
                int num = stoi(s.substr(idx, 2));
                if (num <= 26) { cnt += fCnt(idx+2); }
            }
            memo[idx] = cnt;
            return cnt;
        };
        return fCnt(0);
    }
};
