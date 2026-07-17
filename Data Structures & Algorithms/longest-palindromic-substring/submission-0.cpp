class Solution {
public:
    string longestPalindrome(string s) 
    {
        int size = s.length();
        while (size > 0)
        {
            for (int idx = 0; idx <= s.length()-size; idx++) 
            {
                auto sub = s.substr(idx, size);
                if (checkPalindrom(sub)) { return sub; }
            }
            size--;
        }
        return "";
    }
    bool checkPalindrom(string &s)
    {        
        for (int i = 0; i < s.length()/2; i++)
        {
            if (s[i] != s[s.length()-i-1]) { return false; }
        }
        return true;
    }
};
