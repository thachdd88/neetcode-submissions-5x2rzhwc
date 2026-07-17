class Solution {
public:
    int countSubstrings(string s) 
    {
        vector<string> palSet{};
        int size = s.length();
        while (size > 0)
        {
            for (int idx = 0; idx <= s.length()-size; idx++) 
            {
                auto sub = s.substr(idx, size);
                if (checkPalindrom(sub)) { palSet.push_back(sub); }
            }
            size--;
        }
        return palSet.size();
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
