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
#if 0
            printf("Left %s - Right %s\n", left.c_str(), right.c_str());
            vector<vector<string>> palindromes;
            findPalindrome(right, palindromes);
#else
            vector<vector<string>> palindromes;
            if (isPalindrome(left) && findPalindrome(right, palindromes)) 
            {
                // printf("Right valid: %s\n", right.c_str());
                // for (auto &palin : palindromes) { palin.push_back(left); printList(palin); }
                for (auto &palin : palindromes) { palin.push_back(left); }
                palinList.insert(palinList.end(), palindromes.begin(), palindromes.end());
                found = true;                   
            }
#endif
        }
        return found;
    }

    void printList(vector<string> &strs)
    {
        printf("List: ");
        for (auto &str : strs) { printf("%s, ", str.c_str()); }    
        printf("\n");
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
