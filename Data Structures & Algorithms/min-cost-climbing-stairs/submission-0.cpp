class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int inf = 100000;
        vector<int> solution(n, inf);
        solution[0] = cost[0];
        solution[1] = cost[1];

        for (int fl = 2; fl < n; fl++)
        {
            solution[fl] = min(solution[fl-1], solution[fl-2]) + cost[fl];
        }        
        return min(solution[n-1], solution[n-2]);
    }
};
