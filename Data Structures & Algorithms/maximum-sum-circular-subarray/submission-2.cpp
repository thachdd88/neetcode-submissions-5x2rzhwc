class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total{0};
        int minSum = nums[0];
        int maxSum = nums[0];
        int curMax = 0;
        int curMin = 0;
        for (auto num : nums) {
            curMax = max(curMax+num, num);            
            maxSum = max(maxSum, curMax);
            
            curMin = min(curMin+num, num);
            minSum = min(minSum, curMin);
            total += num;
        }
        if (maxSum < 0) { return maxSum; /* total == minSum */}
        return max(maxSum, total-minSum);
    }
};