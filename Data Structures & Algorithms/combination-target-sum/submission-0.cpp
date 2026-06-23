class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        return combinationSum(0, nums, target);
    }
    vector<vector<int>> combinationSum(int idx, vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        if (idx == nums.size())
        {
            if (target == 0) { res.push_back(vector<int>()); }
            return res;
        }

        res = combinationSum(idx+1, nums, target);
        if (target >= nums[idx]) 
        {
            auto sub = combinationSum(idx, nums, target-nums[idx]);
            int n = sub.size();
            for (int i = 0; i < n; i++)
            {
                sub[i].push_back(nums[idx]);
                res.push_back(sub[i]);
            }
        }
        return res;
    }
};
