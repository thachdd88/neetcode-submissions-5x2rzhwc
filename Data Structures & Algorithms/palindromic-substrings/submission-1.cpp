class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length();
        int cnt = 0; 
        for (int center = 0; center < 2*n-1; center++)
        {
            int l = center / 2;
            int r = l + center % 2;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }    
};
