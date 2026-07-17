class Solution {
public:
#if 1
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
#else
    int numDecodings(string s) 
    {
        if (s.empty()) { return 1;}
        if (s[0] == '0') { return 0;}

        int posibilities = numDecodings(s.substr(1, s.length()-1));
        if (s.length() >= 2)
        {
            int num = stoi(s.substr(0, 2));
            if (num <= 26) { posibilities += numDecodings(s.substr(2, s.length()-2)); }
            return posibilities;
        }
        return posibilities;
    }
#endif
};
