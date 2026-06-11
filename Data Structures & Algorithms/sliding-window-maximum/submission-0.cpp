class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> maxNums{};
        
        int left{0}, right{0};
        while (right < nums.size())
        {
            maxNums[nums[right]] += 1;
            if (right-left+1 == k)
            {
                int maxNum = maxNums.rbegin()->first;
                res.push_back(maxNum);
                maxNums[nums[left]] -= 1;
                if (maxNums[nums[left]] == 0) { maxNums.erase(nums[left]); }
                left++;
            }
            right++;
        }
        // printf("%d: %d\n", maxNums.rbegin()->first, maxNums.rbegin()->second);
        return res;
    }
};
