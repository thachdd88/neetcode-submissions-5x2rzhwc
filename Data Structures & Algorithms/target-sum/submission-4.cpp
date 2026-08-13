class Solution {
public:
#if 1
    int findTargetSumWays(vector<int>& nums, int target) { 
        int total{0};
        for (auto num : nums) { total += num; }

        if ((((target + total) % 2) != 0) || (abs(target) > total)) { return 0; } // no solution

        int positiveSum = (target + total) / 2;
        
        vector<int> dp(positiveSum+1, 0);
        dp[0] = 1; // target = -total;
        for (auto num : nums) {
            for (int amount = positiveSum; amount >= num; amount--) {
                dp[amount] = dp[amount] + dp[amount - num];
            }            
        }
        return dp[positiveSum];
    }
#else
    int findTargetSumWays(vector<int>& nums, int target) {        
        return counting(nums, target, 0);
    }

    int counting(vector<int>& nums, int target, int idx)
    {
        if (idx == nums.size())
        {
            if (target == 0) { return 1; }
            return 0;
        }
        int count = counting(nums, target + nums[idx], idx + 1);
        if (nums[idx] == 0) count += count;
        else
            count += counting(nums, target - nums[idx], idx + 1);
        return count; 
    }
#endif
};
