class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while ((nums[i] > 0) && (nums[i] <= n) && (nums[i] != nums[nums[i]-1])) {
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
        }
        int res = n+1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) { 
                res = i+1;
                break;
            }
        }
        return res;
    }
};