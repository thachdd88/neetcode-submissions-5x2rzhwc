class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        vector<uint64_t> minDist(n, 4000000);
        minDist[0] = 0;
        vector<bool> checked(n, false);
        int dist = 0;
        for (int i = 0; i < n; i++)
        {
            int u = -1;
            for (int j = 0; j < n; j++)
            {
                if (!checked[j] && (u == -1 || minDist[j] < minDist[u]))
                {
                    u = j;
                }
            }
            checked[u] = true;
            dist += minDist[u];

            for (int j = 0; j < n; j++)
            {
                if (!checked[j])
                {
                    int local = abs(points[u][0]-points[j][0]) + abs(points[u][1]-points[j][1]);
                    if (minDist[j] > local) { minDist[j] = local; }
                }
            }
        }

        return dist;
    }
};
