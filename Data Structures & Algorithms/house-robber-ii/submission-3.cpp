class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return 0; }
        if (n == 1) { return nums[0]; }
        if (n == 2) { return max(nums[0], nums[1]); }
        vector<int> rob0(n, 0);
        vector<int> rob1(n, 0);
        rob0[0] = nums[0];
        rob0[1] = max(nums[0], nums[1]);
        rob1[0] = 0;       
        rob1[1] = nums[1]; 
        
        for (int i = 2; i < n; i++)
        {
            rob1[i] = max(rob1[i-1], rob1[i-2] + nums[i]); 
            if (i < n-1) { rob0[i] = max(rob0[i-1], rob0[i-2] + nums[i]); }
            else { rob0[i] = max(rob0[i-1], rob0[i-2]); }
        }
        return max(rob0[n-1], rob1[n-1]);
    }
};
