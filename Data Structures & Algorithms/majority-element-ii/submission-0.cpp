class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int jump = nums.size()/3;
        vector<int> res{};
        int lastNum = 0;
        for (int i = 0; i+jump < nums.size(); i++) {
            if (nums[i] == nums[i+jump]) {
                if (res.empty() || lastNum != nums[i]) {
                    res.push_back(nums[i]);
                    lastNum = nums[i];
                }
            }
        }
        return res;
    }
};