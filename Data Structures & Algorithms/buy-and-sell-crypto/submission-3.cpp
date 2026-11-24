class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixMin(n, 0);
        prefixMin[0] = prices[0];
        vector<int> suffixMax(n, 0);
        suffixMax[n-1] = prices[n-1];
        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i-1], prices[i]);
        }
        for (int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i+1], prices[i]);
        }
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, suffixMax[i]-prefixMin[i]);
        }
        return maxProfit;
    }
};
