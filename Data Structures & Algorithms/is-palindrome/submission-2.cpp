class Solution {
public:
    bool isPalindrome(string s) {
        string transStr = "";
        for (char ch : s) {
            char lowerCh = std::tolower(ch);
            if (('a' <= lowerCh && lowerCh <= 'z') || 
                ('0' <= lowerCh && lowerCh <= '9')) {
                transStr = transStr + lowerCh;
            }
        }
        
        int l{0}, r{(int)transStr.length()-1};
        bool valid{true};
        while (l < r) {
            if (transStr[l] != transStr[r]) {
                valid = false;
                break;
            }
            l++; r--;
        }
        return valid;
    }
};
