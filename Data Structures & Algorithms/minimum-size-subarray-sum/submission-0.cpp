class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        for (int k = 1; k <= n; k++) {
            for (int i = k-1; i < n; i++) {
                sum[i] += nums[i-k+1];
                if (sum[i] >= target) { return k; }
            }
        }
        return 0;   
    }
};