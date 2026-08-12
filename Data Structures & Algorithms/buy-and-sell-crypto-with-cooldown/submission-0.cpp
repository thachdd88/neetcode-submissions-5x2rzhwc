class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> rest(n, 0);
        vector<int> held(n, 0);
        vector<int> sold(n, 0);
        held[0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            held[i] = max(held[i-1], rest[i-1]-prices[i]);
            rest[i] = max(rest[i-1], sold[i-1]);
            sold[i] = held[i-1]+prices[i];
        }
        return max(rest[n-1], sold[n-1]);
    }
};
