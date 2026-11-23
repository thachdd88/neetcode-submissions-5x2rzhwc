class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> found{};
        for (int i = 0; i < ((int)nums.size())-2; i++) {
            if (nums[i] > 0) { break; }
            if (i > 0 && nums[i] == nums[i-1]) { continue; }
            int target = -nums[i];
            int j = i+1;
            int k = ((int)nums.size())-1;
            while (j < k) {
                if ((nums[j] + nums[k]) > target) { k--; }
                else if ((nums[j] + nums[k]) < target) { j++; }
                else {
                    found.insert({nums[i], nums[j]});
                    j++; k--;
                }
            }
        }
        vector<vector<int>> res{};
        for (auto &ij : found) {
            res.push_back({ij.first, ij.second, -ij.first-ij.second}); 
        }
        return res;
    }
};
