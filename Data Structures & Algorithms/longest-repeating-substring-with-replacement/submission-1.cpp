class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int len = s.length();
        int left{0}, right{0}, maxRepeat{0}, maxLen{0};
        map<char, int> chSet{};
        for (right = 0; right < len; right++)
        {
            char ch = s[right];
            chSet[ch] += 1;
            maxRepeat = max(maxRepeat, chSet[ch]);
            // printf("char: %c, left: %d, right: %d, count: %d\n", 
            //     ch, left, right, chSet[ch]);
            if (right-left+1-maxRepeat <= k) 
            {
                maxLen = max(maxLen, right-left+1);
            }
            else 
            {
                chSet[s[left]] -= 1;
                left++;
            }
        }
        return maxLen;
    }
};
