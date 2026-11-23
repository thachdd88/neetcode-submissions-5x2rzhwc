class Solution {
public:
    bool validPalindrome(string s) {
        return checkPalindrome(s, 0, s.length()-1, 0);
    }
    bool checkPalindrome(string &s, int left, int right, int remove) {
        if (left >= right) { return true; }
        else if (s[left] == s[right]) { 
            return checkPalindrome(s, left+1, right-1, remove); 
        }
        else {
            if (remove > 0) { return false; }
            else {
                return checkPalindrome(s, left+1, right, remove+1) || 
                        checkPalindrome(s, left, right-1, remove+1);
            }
        }
    }
};