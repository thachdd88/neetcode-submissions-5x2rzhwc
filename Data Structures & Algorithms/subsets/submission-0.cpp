class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets(0, nums);
    }
    vector<vector<int>> subsets(int idx, const vector<int>& nums)
    {
        vector<vector<int>> res;
        if (idx == nums.size()) { res.push_back(vector<int>()); return res;}

        res = subsets(idx+1, nums);
        int n = res.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> sub = res[i];
            sub.push_back(nums[idx]);
            res.push_back(sub);
        }
        return res; 
    }
};
