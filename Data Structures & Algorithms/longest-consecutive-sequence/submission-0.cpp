class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int maxLen = (sortedNums.size() > 0)? 1 : 0; // 1s number
        int curLen = maxLen;        
        for (int i = 1; i < sortedNums.size(); i++)
        {
            if (sortedNums[i] == (sortedNums[i-1]+1)) { curLen++; }
            else if (sortedNums[i] == (sortedNums[i-1])) { /* ignored */ }
            else
            {
                if (maxLen < curLen) { maxLen = curLen; }
                curLen = 1; // restart new sequence                
            }
        }
        if (maxLen < curLen) { maxLen = curLen; }
        return maxLen;
    }
};
