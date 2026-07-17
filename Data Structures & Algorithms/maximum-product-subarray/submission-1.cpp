class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> producs(n, vector<int>(n, 0));
        int maxProduct = nums[0];
        for (int i = 0; i < n; i++) { producs[i][i] = nums[i]; maxProduct = max(maxProduct, nums[i]); }
        for (int i = 0; i < n-1; i++)
            for (int j = i+1; j < n; j++)
            {
                producs[i][j] = producs[i][j-1]*nums[j];
                maxProduct = max(maxProduct, producs[i][j]); 
            }

        return maxProduct;
    }
};
