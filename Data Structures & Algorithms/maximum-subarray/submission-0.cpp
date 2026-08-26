class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum{nums[0]};
        int n = nums.size();
        vector<int> bestEnds(n, 0);
        bestEnds[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            bestEnds[i] = max(nums[i], bestEnds[i-1]+nums[i]);
            maxSum = max(maxSum, bestEnds[i]);
        }
        return maxSum;
    }
};
