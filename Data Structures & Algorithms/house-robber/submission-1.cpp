class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return 0; }
        if (n == 1) { return nums[0]; }        
        vector<pair<int, bool>> rob(n, {0, false});
        rob[0].first = nums[0];
        rob[0].second = true;

        if (nums[0] >= nums[1]) { rob[1].first = nums[0]; rob[1].second = false; }
        else { rob[1].first = nums[1]; rob[1].second = true; }

        for (int i = 2; i < n; i++)
        {
            if (!rob[i-1].first)
            {
                rob[i].first = max(rob[i-1].first, rob[i-2].first) + nums[i]; 
                rob[i].second = true;
            }
            else
            {
                if (rob[i-1].first > rob[i-2].first + nums[i]) 
                {
                    rob[i].first = rob[i-1].first; 
                    rob[i].second = false;
                }
                else
                {
                    rob[i].first = rob[i-2].first + nums[i]; 
                    rob[i].second = true;
                }
            }
        }
        return rob[n-1].first;
    }
};
