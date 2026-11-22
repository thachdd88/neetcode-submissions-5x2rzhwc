class Solution {
public:
    bool isPalindrome(string s) {        
        int l{0}, r{(int) s.length()-1};
        bool valid{true};
        while (l < r) {
            if (!isalnum(s[l])) { l++; }
            else if (!isalnum(s[r])) { r--; }
            else {
                if (std::tolower(s[l]) != std::tolower(s[r])) {
                    valid = false;
                    break;
                }
                l++; r--;
            }
        }
        return valid;
    }
};
