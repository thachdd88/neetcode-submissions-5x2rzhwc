class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> chCnt_{};
        for (char c : s) { chCnt_[c]++; }
        for (char c : t) { 
            if (chCnt_.find(c) == chCnt_.end()) { return false; }
            chCnt_[c]--;
            if (chCnt_[c] == 0) { chCnt_.erase(c); }
        }
        return chCnt_.empty();
    }
};
