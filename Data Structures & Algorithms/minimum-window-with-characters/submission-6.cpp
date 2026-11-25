class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128U> mapT{};
        int missing = t.length();
        for ( char ch : t) {
            mapT[ch]++;
        }
        
        int left = 0, right = 0, minLen = s.length()+1;
        int minLeft = -1;
        while (right < s.length()) {
            if ( mapT[s[right]] > 0) { missing--; }
            mapT[s[right]]--;

            while (missing == 0) {
                if (right-left+1 < minLen) {
                    minLen = right-left+1;
                    minLeft = left;;
                }
                mapT[s[left]]++;
                if (mapT[s[left]] > 0) { missing++;}
                left++;
            }
            right++;
        }
        if (minLeft < 0) { return ""; }
        return s.substr(minLeft, minLen);
    }
};

// 0 1 2 3 4 (5)
