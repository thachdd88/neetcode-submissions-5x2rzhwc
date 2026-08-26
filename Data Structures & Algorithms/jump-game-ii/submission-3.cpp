class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach{0};
        vector<int> steps(nums.size(), 0);
        for (int i = 0; maxReach < nums.size()-1; i++) {
            if (i+nums[i] > maxReach)
            {
                while (maxReach < nums.size() && maxReach < i+nums[i]) {
                    maxReach++;
                    if (maxReach < nums.size()) {steps[maxReach] = steps[i]+1;}
                }
            }
        }        
        return steps[nums.size()-1];
    }
};
