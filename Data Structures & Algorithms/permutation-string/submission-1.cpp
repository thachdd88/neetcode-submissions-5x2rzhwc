class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string shorter = s1;
        string longer = s2;
        if (shorter.length() > longer.length()) { return false; }
        
        unordered_map<char, int> m1; 
        for (int i = 0; i < shorter.length(); i++) { m1[shorter[i]] += 1; }

        unordered_map<char, int> m2;
        int left{0}, right{0};
        bool found = false;
        while (right < longer.length())
        {
            m2[longer[right]] += 1;
            if (right-left+1 < shorter.length()) { right++; }
            else
            {
                found = (m2 == m1);
                if (found) { break; }
                right++;
                m2[longer[left]] -= 1;
                if ( m2[longer[left]] == 0) { m2.erase(longer[left]); }
                left++;
            }
        }

        return found;
    }
};
