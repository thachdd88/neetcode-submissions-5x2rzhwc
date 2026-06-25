class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> cur; vector<vector<int>> res;
        backtrace(nums, 0, cur, res);
        return res;
    }
    void backtrace(vector<int>& nums, int idx, vector<int> &cur, vector<vector<int>> &res)     
    {
        res.push_back(cur);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i-1]) { continue; }
            cur.push_back(nums[i]);
            backtrace(nums, i+1, cur, res);
            cur.pop_back();
        }
    }
};
