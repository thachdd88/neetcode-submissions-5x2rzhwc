class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> exnum(1, 1);
        for (auto num : nums) { exnum.push_back(num); }
        exnum.push_back(1);

        int n = nums.size()+2;
        vector<vector<int>> maxCoins(n, vector<int>(n, 0));
        for (int size = 2; size < n; size++) {
            for (int l = 0; l < n-size; l++) {
                int r = l + size;     
                // printf("[%d, %d]\n", l, r);     
                for (int mid = l+1; mid < r; mid++) {
                    maxCoins[l][r] = max(maxCoins[l][r], 
                                        maxCoins[l][mid] + maxCoins[mid][r] + exnum[l]*exnum[mid]*exnum[r]);
                }                
            }            
        }      
        return maxCoins[0][n-1];
    }
};
