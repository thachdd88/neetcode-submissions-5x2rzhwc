class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        findPalindrome(s, res);
        return res;
    }
    bool findPalindrome(string s, vector<vector<string>> &palinList)
    {
        bool found{false};

        if (isPalindrome(s)) { palinList.push_back(vector<string>(1, s)); found = true; }
        for (int i = 0; i < s.length()-1; i++)
        {
            string left = s.substr(0, i+1);
            string right = s.substr(i+1, s.length()-i-1);
            vector<vector<string>> palindromes;
            if (isPalindrome(left) && findPalindrome(right, palindromes)) 
            {
                for (auto &palin : palindromes) { palin.push_back(left); palinList.push_back(palin); }
                // palinList.insert(palinList.end(), palindromes.begin(), palindromes.end());
                found = true;                   
            }
        }
        return found;
    }

    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.length()/2; i++)
        {
            if (s[i] != s[s.length()-i-1]) { return false; }
        }
        return true;
    }
};
