class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        if (n > 0) 
        {
            vector<int> minPrices(n, prices[0]);        
            vector<int> maxPrices(n, prices[n-1]);
            for (int i = 1; i < n-1; i++)
            {            
                minPrices[i] = min(minPrices[i-1], prices[i]);
                maxPrices[n-i-1] = max(maxPrices[n-i], prices[n-i-1]);
            }
            for (int i = 0; i < n; i++)
            {
                auto profit = maxPrices[i] - minPrices[i];
                if (maxProfit < profit) { maxProfit = profit; }
            }
        }
        return maxProfit;
    }
};
