class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int subSize = 0;
        int left = 0;
        unordered_set<char> chSet{};
        for (int right = 0; right < s.length(); right++)
        {
            while (chSet.count(s[right]) > 0)
            {
                chSet.erase(s[left]);
                left++;
            }
            subSize = max(subSize, right-left+1);
            chSet.insert(s[right]);
        }
        return subSize;
    }
};
