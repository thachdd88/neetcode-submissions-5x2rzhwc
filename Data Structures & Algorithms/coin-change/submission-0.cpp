class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int inf = 100000;
        vector<int> nums(amount+1, inf);
        nums[0] = 0;
        for (int i = 1; i < amount+1; i++)
        {
            for (auto coin : coins)
                if (i-coin >= 0) { nums[i] = min(nums[i], nums[i-coin]+1); }
        }
        return (nums[amount] == inf) ? -1 : nums[amount];
    }
};
