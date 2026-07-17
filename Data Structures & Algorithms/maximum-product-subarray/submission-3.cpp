class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int final = nums[0];
        for (int i = 1; i < n; i++) 
        {
            int candidate1 = nums[i];
            int candidate2 = maxProduct * nums[i];
            int candidate3 = minProduct * nums[i];

            maxProduct = max(max(candidate1, candidate2), candidate3);
            minProduct = min(min(candidate1, candidate2), candidate3);
            final = max(final, maxProduct);
        }
        
        return final;
    }
};
