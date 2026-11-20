class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res{0};
        for (int win = 1; win <= n; win++) {
            int sum{0};
            for (int i = 0; i+win <= n; i++) {
                if (i == 0) {
                    for (int j = i; j < i+win; j++) { sum += nums[j]; }
                }
                else { sum = sum - nums[i-1] + nums[i+win-1]; }
                if (sum == k) { res++; }
            }
        }
        return res;
    }
};