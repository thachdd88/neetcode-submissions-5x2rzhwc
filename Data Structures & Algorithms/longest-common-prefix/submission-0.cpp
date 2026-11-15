class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) { return ""; }

        string longestPre = strs[0];
        int preLen = longestPre.length();
        for (auto &str : strs) {
            int cIdx;
            for (cIdx = 0; cIdx < preLen; cIdx++) {
                if (cIdx >= str.length()) { break; }
                if (str[cIdx] != longestPre[cIdx]) { break; }
            }
            preLen = cIdx; 
        }
        return longestPre.substr(0, preLen);
    }
};