class Solution {
public:
    int change(int amount, vector<int>& coins) {
        counts = vector<vector<int>>(coins.size(), vector<int>(amount+1, -1));        
        
        return counting(amount, coins, 0);
    }
    int counting(int amount, vector<int>& coins, int idx) {
        if (amount == 0) { return 1; }
        if (idx >= counts.size()) { return 0; }
        if (counts[idx][amount] != -1) { return counts[idx][amount]; }

        counts[idx][amount] = counting(amount, coins, idx+1); // not use coins[idx]
        if (amount >= coins[idx])
            counts[idx][amount] += counting(amount-coins[idx], coins, idx); // use coins[idx]
        
        return counts[idx][amount];
    }
private:
    vector<vector<int>> counts;
};
