class Solution {
public:
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
};
