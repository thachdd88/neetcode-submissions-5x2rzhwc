class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> selected(nums.size(), 0);
        auto subs = permute(nums, selected);
        vector<vector<int>> res;
        for (auto &sub : subs) { if (sub.size() == nums.size()) { res.push_back(sub); } }
        return res;
    }
    vector<vector<int>> permute(vector<int>& nums, vector<int> &selected) 
    {
        vector<vector<int>> res(1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (selected[i] == 0)
            {
                selected[i] = 1; 
                vector<vector<int>> subs = permute(nums, selected);
                for (auto &sub : subs) 
                { 
                    sub.push_back(nums[i]); res.push_back(sub); 
                }
                selected[i] = 0; 
            }            
        }
        return res; 
    }
};
