class Solution {
public:
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
};
